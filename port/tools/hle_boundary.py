"""HLE boundary report: what the game needs from BIOS + the resident API.

Reads port/analysis/functions.json (from inventory.py) and produces:
  - list of BIOS syscalls actually used (table A0/B0/C0 + number + name)
  - resident API: SCPS functions called from overlays, ranked by fan-in
Output: port/analysis/hle_boundary.json + hle_boundary.md
"""
import json
from collections import Counter, defaultdict
from pathlib import Path

ANALYSIS = Path(__file__).resolve().parents[1] / "analysis"

# Names from psx-spx BIOS function tables (only entries we are confident of).
BIOS_NAMES = {
    (0xA0, 0x13): "SaveState", (0xA0, 0x17): "strcmp", (0xA0, 0x18): "strncmp",
    (0xA0, 0x19): "strcpy", (0xA0, 0x1B): "strlen", (0xA0, 0x28): "bzero",
    (0xA0, 0x2A): "memcpy", (0xA0, 0x2B): "memset", (0xA0, 0x33): "malloc",
    (0xA0, 0x34): "free", (0xA0, 0x39): "InitHeap", (0xA0, 0x3F): "printf",
    (0xA0, 0x44): "FlushCache", (0xA0, 0x70): "_bu_init",
    (0xA0, 0x72): "CdRemove", (0xA0, 0x78): "CdAsyncSeekL",
    (0xA0, 0x7C): "CdAsyncGetStatus", (0xA0, 0x7E): "CdAsyncReadSector",
    (0xA0, 0x81): "CdAsyncSetMode", (0xA0, 0x90): "CdromIoIrqFunc1",
    (0xA0, 0x91): "CdromDmaIrqFunc1", (0xA0, 0x92): "CdromIoIrqFunc2",
    (0xA0, 0x93): "CdromDmaIrqFunc2", (0xA0, 0x94): "CdromGetInt5errCode",
    (0xA0, 0x95): "CdInitSubFunc", (0xA0, 0x96): "AddCDROMDevice",
    (0xA0, 0x9D): "GetConf", (0xA0, 0x9C): "SetConf",
    (0xA0, 0xA1): "SystemErrorBootOrDiskFailure", (0xA0, 0xA2): "EnqueueCdIntr",
    (0xA0, 0xA3): "DequeueCdIntr", (0xA0, 0xA5): "ReadSector",
    (0xA0, 0xA6): "get_cd_status", (0xA0, 0xA9): "bufs_cb_2",
    (0xB0, 0x00): "alloc_kernel_memory", (0xB0, 0x07): "DeliverEvent",
    (0xB0, 0x08): "OpenEvent", (0xB0, 0x09): "CloseEvent",
    (0xB0, 0x0B): "TestEvent", (0xB0, 0x0C): "EnableEvent",
    (0xB0, 0x0D): "DisableEvent", (0xB0, 0x12): "InitPad",
    (0xB0, 0x13): "StartPad", (0xB0, 0x14): "StopPad",
    (0xB0, 0x17): "ReturnFromException", (0xB0, 0x18): "SetDefaultExitFromException",
    (0xB0, 0x19): "SetCustomExitFromException", (0xB0, 0x20): "UnDeliverEvent",
    (0xB0, 0x32): "FileOpen", (0xB0, 0x34): "FileRead", (0xB0, 0x35): "FileWrite",
    (0xB0, 0x36): "FileClose", (0xB0, 0x3D): "std_out_putchar",
    (0xB0, 0x47): "AddMemCardDevice", (0xB0, 0x4A): "InitCard",
    (0xB0, 0x4B): "StartCard", (0xB0, 0x4C): "StopCard",
    (0xB0, 0x56): "GetC0Table", (0xB0, 0x57): "GetB0Table",
    (0xB0, 0x5B): "ChangeClearPad",
    (0xC0, 0x00): "EnqueueTimerAndVblankIrqs", (0xC0, 0x01): "EnqueueSyscallHandler",
    (0xC0, 0x02): "SysEnqIntRP", (0xC0, 0x03): "SysDeqIntRP",
    (0xC0, 0x07): "InstallExceptionHandlers", (0xC0, 0x08): "SysInitMemory",
    (0xC0, 0x0A): "ChangeClearRCnt", (0xC0, 0x0C): "InitDefInt",
    (0xC0, 0x12): "InstallDevices", (0xC0, 0x1C): "AdjustA0Table",
}


def main():
    report = json.loads((ANALYSIS / "functions.json").read_text())

    # 1. all BIOS syscalls used
    syscalls = Counter()
    syscall_sites = defaultdict(list)
    for mod, m in report.items():
        for f in m["functions"]:
            for table, num in f["syscalls"]:
                syscalls[(table, num)] += 1
                syscall_sites[(table, num)].append((mod, f["ram"]))

    # 2. resident API: SCPS functions called from overlays
    scps = report["SCPS"]
    scps_funcs = {f["ram"] for f in scps["functions"]}
    fan_in = Counter()
    overlay_callers = defaultdict(set)
    for mod, m in report.items():
        if mod == "SCPS":
            continue
        for f in m["functions"]:
            for tgt in f["callees"]:
                if scps["lo"] <= tgt < scps["hi"]:
                    fan_in[tgt] += 1
                    overlay_callers[tgt].add(mod)

    unresolved = sorted(t for t in fan_in if t not in scps_funcs)

    lines = ["# HLE boundary — Alundra 2 JP (SCPS-101.15)", ""]
    lines.append("## BIOS syscalls used (entire game)")
    lines.append("")
    lines.append("| Table | Num | Name | Stub sites |")
    lines.append("|---|---|---|---|")
    for (table, num), n in sorted(syscalls.items()):
        name = BIOS_NAMES.get((table, num), "?")
        nums = "?" if num is None else f"0x{num:02X}"
        sites = ", ".join(f"{m}:0x{r:08X}" for m, r in syscall_sites[(table, num)][:3])
        lines.append(f"| 0x{table:02X} | {nums} | {name} | {sites} |")

    lines.append("")
    lines.append("## Resident API (SCPS functions called from overlays)")
    lines.append("")
    lines.append(f"Total distinct SCPS targets called from overlays: {len(fan_in)}")
    lines.append(f"Targets not matching a known function start: {len(unresolved)}")
    lines.append("")
    lines.append("| SCPS addr | callers (call sites) | overlays |")
    lines.append("|---|---|---|")
    for tgt, n in fan_in.most_common(60):
        mods = ",".join(sorted(overlay_callers[tgt]))
        lines.append(f"| 0x{tgt:08X} | {n} | {mods} |")

    (ANALYSIS / "hle_boundary.md").write_text("\n".join(lines) + "\n")
    (ANALYSIS / "hle_boundary.json").write_text(json.dumps({
        "syscalls": [
            {"table": t, "num": n, "name": BIOS_NAMES.get((t, n)),
             "uses": c} for (t, n), c in sorted(syscalls.items())],
        "resident_api": [
            {"ram": tgt, "fan_in": c,
             "overlays": sorted(overlay_callers[tgt])}
            for tgt, c in fan_in.most_common()],
        "unresolved_targets": unresolved,
    }))
    print(f"{len(syscalls)} distinct BIOS syscalls; "
          f"{len(fan_in)} resident API entry points "
          f"({len(unresolved)} unresolved)")
    print("wrote hle_boundary.md / hle_boundary.json")


if __name__ == "__main__":
    main()
