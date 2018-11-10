#!/bin/sh
set -e
. ./iso.sh

#qemu-system-$(./target-triplet-to-arch.sh $HOST) -cdrom myos.iso
qemu-system-x86_64 -cdrom myos.iso
#qemu-system-x86_64 -kernel kernel/myos.kernel
./clean.sh