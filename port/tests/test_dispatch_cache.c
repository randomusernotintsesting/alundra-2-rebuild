/* Compile with -finstrument-functions for resolver-work assertions. Guest
 * bodies are unique, harmless stubs; all six address tables and dispatch.c
 * itself are production code. No instrumentation enters the application. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "psx_rt.h"

static unsigned pad_env_reads;
static int pad_enabled;
static char *fixture_getenv(const char *name) {
    if (!strcmp(name, "A2_TRACE_PAD")) {
        pad_env_reads++;
        return pad_enabled ? "1" : NULL;
    }
    return NULL;
}

#define getenv fixture_getenv
#define A2_NATIVE_SAVES 1
#ifndef A2_DISPATCH_SOURCE
#define A2_DISPATCH_SOURCE "../src/dispatch.c"
#endif
#include A2_DISPATCH_SOURCE
#undef getenv
#include "test_dispatch_tables.inc"

/* Diagnostic tests redirect stderr; assertion failures must still reach
 * CTest/the terminal instead of disappearing into the temporary log. */
static int original_stderr = -1;
static void fixture_assert_failed(const char *expression, int line) {
    if (original_stderr >= 0) dup2(original_stderr, STDERR_FILENO);
    fprintf(stderr, "%s:%d: assertion failed: %s\n", __FILE__, line, expression);
    abort();
}
#undef assert
#define assert(expression) ((expression) ? (void)0 : fixture_assert_failed(#expression, __LINE__))

static unsigned table_searches;
#ifndef A2_DISPATCH_BENCH
void __attribute__((no_instrument_function))
__cyg_profile_func_enter(void *function, void *caller) {
    (void)caller;
    if (function == (void *)bsearch_table) table_searches++;
}
void __attribute__((no_instrument_function))
__cyg_profile_func_exit(void *function, void *caller) {
    (void)function; (void)caller;
}
#endif

uint32_t seq_ticks, psx_frame_no, psx_work;
int psx_bb_budget = 1000000;
static unsigned bios_calls, interp_calls, save_calls;
static uint32_t bios_table, bios_number, interpreted, save_address, save_target;
void psx_bb_fire(void) { psx_bb_budget = 1000000; }
void kernel_syscall(uint32_t table, uint32_t number) {
    bios_calls++; bios_table = table; bios_number = number; R[2] = 0xB105;
}
void psx_interp(uint32_t address) {
    interp_calls++; interpreted = address; R[2] = 0x1A7E;
    psx_next = R[31];
}
int a2_native_save_handle(uint32_t address) {
    save_calls++; save_address = address;
    if (address != save_target) return 0;
    R[2] = 0x5A7E; psx_next = R[31]; return 1;
}
uint32_t psx_mmio_read(uint32_t address, int size) {
    (void)address; (void)size; assert(!"Unexpected dispatch MMIO read"); return 0;
}
void psx_mmio_write(uint32_t address, uint32_t value, int size) {
    (void)address; (void)value; (void)size; assert(!"Unexpected dispatch MMIO write");
}
uint32_t psx_irq_active(void) { return 0; }
void psx_irq_dispatch(void) { assert(!"Unexpected dispatch IRQ"); }
int a2_modelcap_active(void) { return 0; }
FILE *a2_modelcap_file(void) { return NULL; }

typedef void (*target_fn)(void);
typedef struct { const psx_func_entry *entries; int count; uint32_t id; } table_info;
static table_info tables[6];
static psx_func_entry oracle_hle[256];
static unsigned oracle_hle_count;
static unsigned checked;

static void set_overlay(uint32_t id) {
    memcpy(PSX_RAM + 0x811D8, &id, sizeof id);
}

/* Frozen uncached resolver algorithm, independent of the cache and its
 * helpers. Own override state catches missing registration invalidation. */
static target_fn oracle(uint32_t address, uint32_t id) {
    for (unsigned i = 0; i < oracle_hle_count; i++)
        if (oracle_hle[i].addr == address) return oracle_hle[i].fn;
    const table_info *table = &tables[0];
    if (address >= 0x800811D8u) {
        table = NULL;
        for (unsigned i = 1; i < 6; i++)
            if (tables[i].id == id) table = &tables[i];
        if (!table) return NULL;
    }
    int lo = 0, hi = table->count - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (table->entries[mid].addr == address) return table->entries[mid].fn;
        if (table->entries[mid].addr < address) lo = mid + 1;
        else hi = mid - 1;
    }
    return NULL;
}

static void check(uint32_t address, uint32_t id) {
    set_overlay(id);
    target_fn expected = oracle(address, id);
    assert(lookup(address) == expected);
    assert(lookup(address) == expected); /* cold and repeated result */
    checked++;
}

static void register_hle(uint32_t address, target_fn fn) {
    assert(oracle_hle_count < 256);
    oracle_hle[oracle_hle_count++] = (psx_func_entry){address, fn};
    psx_register_hle(address, fn);
}
static void first_hle(void) { R[2] = 0x1111; }
static void second_hle(void) { R[2] = 0x2222; }

static void repeated_lookup_skips_search(void) {
    uint32_t address = scps_table[0].addr;
    assert(lookup(address) == scps_table[0].fn);
    table_searches = 0;
    for (unsigned i = 0; i < 100; i++)
        assert(lookup(address) == scps_table[0].fn);
#ifndef A2_DISPATCH_BENCH
    if (table_searches) {
        printf("Unexpected searches on repeated target: %u\n", table_searches);
        fflush(stdout);
    }
    assert(table_searches == 0); /* RED: baseline performs 100 searches. */
#endif
}

static void all_tables_and_aliases(void) {
    for (unsigned table = 0; table < 6; table++) {
        const table_info *t = &tables[table];
        for (int i = 0; i < t->count; i++) {
            uint32_t address = t->entries[i].addr;
            if (i) assert(t->entries[i - 1].addr < address);
            set_overlay(t->id);
            assert(lookup(address) == t->entries[i].fn);
            /* Alternating IDs at every real address detects stale overlay
             * hits, including entries missing from the next overlay. */
            for (uint32_t id = 4; id <= 8; id++) check(address, id);
            check(address & 0x1FFFFFFFu, t->id);
            check(address | 0xA0000000u, t->id);
            check(address + 1, t->id); /* exact, unaligned miss */
        }
    }
    const uint32_t misses[] = {0, 1, 0x80000000, 0x800811D8, 0x801FFFFF,
        0xFFFFFFFF, 0x8005D000, 0xA0017000};
    for (unsigned i = 0; i < sizeof misses / sizeof misses[0]; i++)
        for (uint32_t id = 4; id <= 8; id++) check(misses[i], id);
}

static void collisions_do_not_return_other_targets(void) {
    uint32_t address = scps_table[0].addr;
    unsigned evictions = 0;
    /* Discover collisions by observed resolver work; do not duplicate the
     * production hash or inspect its private layout. All answers stay exact. */
    for (int i = 1; i < game00_table_n; i++) {
        check(address, 4);
        check(game00_table[i].addr, 4);
        table_searches = 0;
        assert(lookup(address) == scps_table[0].fn);
        evictions += table_searches != 0;
    }
#ifndef A2_DISPATCH_BENCH
    assert(evictions > 0);
#else
    (void)evictions;
#endif
}

static void registration_invalidates_resolved_targets(void) {
    uint32_t resident = scps_table[1].addr, overlay = game00_table[0].addr;
    check(resident, 4);
    register_hle(resident, first_hle);
    check(resident, 4);
    assert(lookup(resident) == first_hle);
    register_hle(resident, second_hle);
    assert(lookup(resident) == first_hle); /* earliest duplicate wins */
    for (uint32_t id = 4; id <= 8; id++) check(overlay, id);
    register_hle(overlay, first_hle);
    for (uint32_t id = 0; id <= 9; id++) {
        check(overlay, id);
        assert(lookup(overlay) == first_hle);
    }
    check(0x80006004, 4);
    register_hle(0x80006004, second_hle);
    assert(lookup(0x80006004) == second_hle); /* previous miss */
    uint32_t null_address = scps_table[2].addr;
    check(null_address, 4);
    register_hle(null_address, NULL);
    register_hle(null_address, second_hle);
    assert(lookup(null_address) == NULL); /* null first override also wins */
}

static void call_and_check(uint32_t address, uint32_t result) {
    R[2] = 0; R[31] = 0x87654321; psx_next = 0x88776655;
    uint32_t work = psx_work, ticks = seq_ticks;
    psx_call(address);
    assert(R[2] == result && R[31] == 0x87654321 && psx_next == 0x88776655);
    assert(psx_work == work + 1); /* cache cannot alter segment cadence */
    assert(seq_ticks == ticks + (address == 0x8002C52Cu));
}

static void dispatcher_boundaries(void) {
    set_overlay(4);
    uint32_t address = scps_table[3].addr;
    scps_table[3].fn(); uint32_t expected = R[2];
    call_and_check(address, expected);
    call_and_check(address & 0x1FFFFFFF, expected); /* psx_call canonicalizes */
    target_fn sequence_tick = oracle(0x8002C52C, 4);
    assert(sequence_tick);
    sequence_tick(); uint32_t tick_result = R[2];
    call_and_check(0x8002C52C, tick_result);
    call_and_check(0x8002C52C, tick_result); /* same cadence on a warmed hit */
    uint32_t alias = address | 0xA0000000;
    call_and_check(alias, 0x1A7E); assert(interpreted == alias);
    register_hle(alias, first_hle);
    call_and_check(alias, 0x1111); /* exact alias HLE is independent */
    register_hle(0x6000, first_hle);
    call_and_check(0x6000, 0x1111); /* raw-address second lookup */
    register_hle(0x80006000, second_hle);
    call_and_check(0x6000, 0x2222); /* canonical lookup has precedence */
    call_and_check(0x7000, 0x1A7E); assert(interpreted == 0x7000);
    unsigned old_interp = interp_calls;
    call_and_check(0x7000, 0x1A7E);
    assert(interp_calls == old_interp + 1); /* miss still reaches interpreter */
    register_hle(0x80007000, first_hle);
    call_and_check(0x7000, 0x1111);
    for (uint32_t table = 0xA0; table <= 0xC0; table += 0x10) {
        register_hle(table | 0x80000000, second_hle);
        for (unsigned alias_index = 0; alias_index < 3; alias_index++) {
            const uint32_t prefix[] = {0, 0x80000000, 0xA0000000};
            unsigned before_bios = bios_calls, before_save = save_calls;
            R[9] = 0x1234;
            call_and_check(table | prefix[alias_index], 0xB105);
            assert(bios_calls == before_bios + 1 && save_calls == before_save);
            assert(bios_table == table && bios_number == 0x1234);
        }
    }
    assert(lookup(address) == scps_table[3].fn); /* warm entry before native hook */
    save_target = address;
    call_and_check(address & 0x1FFFFFFF, 0x5A7E);
    assert(save_address == address);
    save_target = 0;
    call_and_check(address, expected);
}

static long log_size(FILE *log) {
    fflush(stderr);
    return ftell(log);
}

static void pad_environment_is_gated_and_mutable(FILE *log) {
    register_hle(0x80043BFF, first_hle);
    register_hle(0x80043C00, first_hle);
    register_hle(0x80044D00, first_hle);
    register_hle(0x80044D01, first_hle);
    pad_enabled = 0; pad_env_reads = 0;
    call_and_check(0x80043BFF, 0x1111);
    call_and_check(0x80044D01, 0x1111);
    if (pad_env_reads) {
        printf("Unexpected A2_TRACE_PAD reads outside PC range: %u\n", pad_env_reads);
        fflush(stdout);
    }
    assert(pad_env_reads == 0); /* RED: baseline calls getenv outside range. */
    long start = log_size(log);
    call_and_check(0x80043C00, 0x1111);
    assert(pad_env_reads == 1 && log_size(log) == start);
    pad_enabled = 1;
    call_and_check(0x80043C00, 0x1111);
    long enabled = log_size(log);
    assert(pad_env_reads == 2 && enabled > start);
    pad_enabled = 0;
    call_and_check(0x80044D00, 0x1111);
    assert(pad_env_reads == 3 && log_size(log) == enabled);
    pad_enabled = 1;
    call_and_check(0x80044D00, 0x1111);
    assert(pad_env_reads == 4 && log_size(log) > enabled);
    pad_enabled = 0;
}

static void unresolved_overlay_diagnostics_repeat(FILE *log) {
    set_overlay(0);
    uint32_t address = game00_table[10].addr;
    long before = log_size(log);
    assert(lookup(address) == NULL);
    long once = log_size(log);
    assert(lookup(address) == NULL);
    long twice = log_size(log);
    assert(once > before && twice - once == once - before);
    check(address, 4); /* invalid ID must not poison later loaded overlay */
    set_overlay(0);
    assert(lookup(address) == NULL); /* nor may a prior hit suppress failure */
}

#ifdef A2_DISPATCH_BENCH
static target_fn volatile benchmark_sink;
static void benchmark(void) {
    const unsigned iterations = 2000000;
    set_overlay(4);
    clock_t start = clock();
    for (unsigned i = 0; i < iterations; i++)
        benchmark_sink = oracle(game00_table[1000 + (i & 63)].addr, 4);
    double uncached = (double)(clock() - start) / CLOCKS_PER_SEC;
    start = clock();
    for (unsigned i = 0; i < iterations; i++)
        benchmark_sink = lookup(game00_table[1000 + (i & 63)].addr);
    double cached = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Synthetic 64-target resolver loop, %u calls: oracle %.6fs, production %.6fs\n",
           iterations, uncached, cached);
}
#endif

int main(int argc, char **argv) {
    tables[0] = (table_info){scps_table, scps_table_n, 4};
    tables[1] = (table_info){game00_table, game00_table_n, 4};
    tables[2] = (table_info){event00_table, event00_table_n, 5};
    tables[3] = (table_info){game01_table, game01_table_n, 6};
    tables[4] = (table_info){game02_table, game02_table_n, 7};
    tables[5] = (table_info){game03_table, game03_table_n, 8};
#ifdef A2_DISPATCH_BENCH
    if (argc > 1 && !strcmp(argv[1], "--benchmark")) {
        benchmark();
        return 0;
    }
#endif
    FILE *log = tmpfile(); assert(log);
    original_stderr = dup(STDERR_FILENO); assert(original_stderr >= 0);
    assert(dup2(fileno(log), STDERR_FILENO) >= 0);
    if (argc > 1 && !strcmp(argv[1], "--red-pad")) {
        pad_environment_is_gated_and_mutable(log);
    } else {
        repeated_lookup_skips_search();
        all_tables_and_aliases();
        collisions_do_not_return_other_targets();
        registration_invalidates_resolved_targets();
        dispatcher_boundaries();
        pad_environment_is_gated_and_mutable(log);
        unresolved_overlay_diagnostics_repeat(log);
    }
    fflush(stderr); assert(dup2(original_stderr, STDERR_FILENO) >= 0);
    close(original_stderr); original_stderr = -1; fclose(log);
    printf("PASS: %u resolver cases, all generated targets, overlay/alias/HLE/collision/fallback/BIOS/native-save/cadence/pad contracts\n", checked);
#ifdef A2_DISPATCH_BENCH
    benchmark();
#endif
    return 0;
}
