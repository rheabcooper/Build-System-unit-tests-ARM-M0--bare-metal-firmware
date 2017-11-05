#!/bin/bash

# This is a shell script to perform remote install
# of project2 executable on the KL25Z platform
#
#

BUILD_CONFIG="PLATFORM=KL25Z MAIN=PROJECT2"

# Shell command scripts to install project2 to the board
make clean
make build $BUILD_CONFIG
arm-none-eabi-objcopy -S -O binary project2.elf project2.bin
sudo cp project2.bin /media/brian/MBED
