#!/bin/bash

# This is a shell script to perform remote install
# of project2 executable on the KL25Z platform
#
#

BUILD="make build PLATFORM=KL25Z MAIN=PROJECT2"
MOUNT_PORT="/dev/sdb1"
MOUNT_DIR="mount_kl25z"
PROJ2_EXE="project2.elf"

# Steps to complete the remote install on kl25z
$BUILD
mkdir $MOUNT_DIR
sudo mount $MOUNT_PORT $MOUNT_DIR
sudo cp $PROJ2_EXE ../$MOUNT_DIR



