#!/bin/bash

# This is a shell script to perform remote install
# of project2 executable on the KL25Z platform
#
#

# --- Build and Install Parameters
BUILD_CONFIG="PLATFORM=KL25Z MAIN=PROJECT2"
MOUNT_DIR="/media/brian/FRDM-KL25Z"
PROJ_EXE="project2.elf"


# Shell command scripts to complete the remote install on kl25z
make build $BUILD_CONFIG
sudo cp $PROJ_EXE $MOUNT_DIR



