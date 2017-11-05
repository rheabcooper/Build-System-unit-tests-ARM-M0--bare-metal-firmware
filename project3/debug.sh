#!/bin/bash

# This is a bash shell script to build the kl25z executable
# and then run gdb debugging automatically.

#---- Build and Debug parameters -----
BUILD_CONFIG="PLATFORM=KL25Z MAIN=PROJECT2"
PROJ_EXE="project2.elf"
GDB_SCRIPT="kl25z_gdb.gdb"

HELLO_EXE="/home/brian/Downloads/mbed_blinky2_kl25z.bin"

# ---- Start the shell command script ----
#make clean
#make build $BUILD_CONFIG
arm-none-eabi-gdb $HELLO_EXE -x $GDB_SCRIPT
