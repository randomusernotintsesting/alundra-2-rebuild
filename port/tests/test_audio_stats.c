/* The only fake is the SDL device; CD controller, XA decoder and mixer are real. */
#define main existing_output_test_main
#include "test_audio_output.c"
#undef main
#include "../src/cdrom.c"
#include <unistd.h>
uint8_t PSX_RAM[PSX_RAM_SIZE];
int psx_in_irq, psx_critical;
uint32_t psx_frame_no;
void psx_irq_set(int bit) { (void)bit; }
void psx_irq_dispatch(void) { irq_fl = 0; }
void a2_ramwatch_blk(uint32_t dst, uint32_t len, const char *tag) {
    (void)dst; (void)len; (void)tag;
}

static struct {
    uint64_t frames, nonzero, energy;
} captured_source;
static void capture_source_tick(void) {
    /* Snapshot the actual reconstructed source about to be consumed, without
     * reading any diagnostic fields. Pending FIFO frames beyond this tick
     * must not contribute to the reported consumed energy. Filter correctness
     * itself has independent impulse/coefficient tests in audio_resample. */
    unsigned frames = cd_count < 735 ? cd_count : 735;
    for (unsigned i = 0; i < frames; i++) {
        unsigned at = (cd_read + i) % CD_FRAMES;
        int64_t left = cd_pcm[at][0], right = cd_pcm[at][1];
        captured_source.energy += (uint64_t)(left*left + right*right);
        captured_source.nonzero += left != 0 || right != 0;
    }
    captured_source.frames += frames;
}
static uint64_t report_field(const char *output, unsigned tick, const char *key) {
    char prefix[48]; snprintf(prefix,sizeof prefix,"audiostat: tick=%u ",tick);
    const char *line = strstr(output,prefix); assert(line);
    const char *end = strchr(line,'\n'); assert(end);
    const char *field = strstr(line,key); assert(field && field < end);
    const char *value = field + strlen(key);
    char *after;
    uint64_t result = strtoull(value,&after,10);
    assert(after > value && after <= end);
    return result;
}

int main(void) {
    assert(setenv("A2_AUDIOSTAT", "1", 1) == 0);
    FILE *log = tmpfile(); assert(log);
    int saved = dup(STDERR_FILENO); assert(saved >= 0);
    assert(dup2(fileno(log), STDERR_FILENO) >= 0);
    img = tmpfile(); assert(img);
    uint8_t raw[2352] = {0};
    raw[15] = 2; raw[16] = raw[20] = 1;
    raw[18] = raw[22] = 0x64; raw[19] = raw[23] = 1;
    for (int g = 0; g < 18; g++) memset(raw + 40 + 128*g, 0x21, 112);
    for (int i = 0; i < 160; i++) {
        raw[17] = raw[21] = i % 8 ? 1 : 0;
        assert(fwrite(raw, 1, 2352, img) == 2352);
    }
    fflush(img); img_sectors = 160;
    mode = 0xc8; reading = 1; irq_en = 0x1f;
    param[0] = 1; param[1] = 0; cd_command(0x0d);
    spu_write(0x1aa, 0xc001);
    spu_write(0x1b0, 0x7fff); spu_write(0x1b2, 0x7fff);
    for (int i = 0; i < 60; i++) {
        psx_frame_no++; cd_vblank(); capture_source_tick(); spu_vblank();
    }
    /* 2352 samples every8 sectors; delivery ticks1,4,7,10,14,17...
     * leave a147-sample gap at tick13 before the next sector arrives. */
    assert(cur_lba == 150 && cd_count == 735);
    assert(captured_source.frames == 43953 && captured_source.nonzero == 43953);
    uint64_t energy_at60 = captured_source.energy;
    assert(energy_at60 > 0);
    cd_command(0x09);
    /* A complete decoded source block can be consumed while CD mixing is off. */
    spu_write(0x1aa, 0xc000);
    int16_t pcm[48]; for (int i = 0; i < 48; i++) pcm[i] = 1000;
    spu_push_cd_audio(pcm, 24, 37800); capture_source_tick(); spu_vblank();
    assert(captured_source.frames == 43981 && captured_source.nonzero == 43981);
    assert(cd_count == 0 && captured_source.energy > energy_at60);
    reset_host(1024); spu_set_sound(1); prime();
    consume(14700); spu_vblank();
    for (int i = 0; i < 4; i++) spu_vblank();
    for (int i = 0; i < 9; i++) spu_vblank();
    spu_set_sound(0);
    /* Total120 audio ticks: source starvation and host starvation are distinct. */
    for (int i = 0; i < 40; i++) spu_vblank();
    fflush(stderr);
    assert(dup2(saved, STDERR_FILENO) >= 0); close(saved);
    rewind(log); char output[16384];
    size_t n = fread(output, 1, sizeof output-1, log); output[n] = 0;
    assert(strstr(output, "cdstat: tick=60"));
    assert(strstr(output, "advanced=150 xa_selected=19 xa_frames=38304"));
    assert(strstr(output, "xa_rate=37800"));
    assert(strstr(output, "cd_consumed=43953 cd_missing=147 cd_nonzero=43953"));
    assert(strstr(output, "cd_consumed=43981 cd_missing=44219 cd_nonzero=43981"));
    /* Statistics must match independently captured consumed PCM, including
     * filter startup and the final block consumed while mixing is disabled. */
    assert(report_field(output,60,"cd_energy=") == energy_at60);
    assert(report_field(output,120,"cd_energy=") == captured_source.energy);
    assert(report_field(output,60,"cd_dropped=") == 0);
    assert(report_field(output,120,"cd_dropped=") == 0);
    assert(strstr(output, "cd_mixed_nonzero=43953 voice_nonzero=0"));
    assert(strstr(output, "host_starve=1 host_overflow=1"));
    assert(strstr(output, "audioqueueempty: frame=67 tick=67 gap_ticks="));
    assert(strstr(output, "prime_bytes=12288"));
    fclose(log); fclose(img);
    puts("audio diagnostics distinguish source consumption, source gaps and host recovery");
    return 0;
}
