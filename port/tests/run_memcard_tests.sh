#!/bin/sh
set -eu
cd "$(dirname "$0")/../.."
test_dir=$(mktemp -d /tmp/alundra-memcard-build.XXXXXX)
trap 'rm -f "$test_dir/test_memcard"; rmdir "$test_dir"' EXIT HUP INT TERM
${CC:-cc} -std=gnu11 -Wall -Wextra -Werror ${SANITIZE:+-fsanitize=address,undefined} \
    -Iport/src port/tests/test_memcard.c port/src/kernel_hle.c port/src/memcard.c \
    -o "$test_dir/test_memcard"
"$test_dir/test_memcard"
