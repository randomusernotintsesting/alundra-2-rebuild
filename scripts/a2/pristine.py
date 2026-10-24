"""Pristine-source bookkeeping.

Insertion tools write into disc/ in place, so reading their input from
disc/ would layer every run on top of the previous one (and a cleared
translation would never restore the original text). Instead, the first
time a file is needed its untouched copy is stashed in originals/ (next
to the disc dir), and all dump/insert tools read from there.

The stash therefore must be created while disc/ is pristine - i.e. before
the first insertion, which is automatic in the normal workflow
(extract -> dump -> translate -> insert).
"""
import os
import shutil


def source(disc, rel):
    """Path to the pristine copy of <disc>/<rel>, stashing it on first use.
    Stash lives next to the disc dir as <disc>.orig/ (per-disc, so US and
    JP extractions never mix)."""
    stash = os.path.join(os.path.abspath(disc) + ".orig", rel)
    if not os.path.exists(stash):
        os.makedirs(os.path.dirname(stash), exist_ok=True)
        shutil.copy2(os.path.join(disc, rel), stash)
    return stash
