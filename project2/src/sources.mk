#####################################################
#													
#	@file sources.mk								
#	@brief A source file for the build of project 2	
#													
#	This file was all developed by Brian Kelly.						
#									 				
# 	@author Brian Kelly								
#	@date September 24, 2017						
#													
#####################################################

# Set up the location for the project directory
MYDIR = /home/brian/repos/BMK-ecen5813-project1

# login info for the BeagleBone Black
BBB_ROOT = root@192.168.240.31
BBB_USER = debian@192.168.240.31
BBB_USB_ROOT = root@192.168.7.2
BBB_USB_USER = debian@192.168.7.2

#File Paths on the BeagleBone Black
BBB_USER_DIR = /home/debian
BBB_USER_BIN = $(BBB_USER_DIR)/bin

# Project Master or Top Level Directory
PROJ_DIR 		= $(MYDIR)/project2

# Subdirectories under the Master Directory
INC_DIR 		= $(PROJ_DIR)/include
LIB_DIR 		= $(PROJ_DIR)/lib
PLATFORM_DIR 	= $(PROJ_DIR)/platform
SRC_DIR 		= $(PROJ_DIR)/src
OBJ_DIR			= $(PROJ_DIR)/obj
DEP_DIR			= $(PROJ_DIR)/dep

# Source Directory
MAIN_SRC 		= $(SRC_DIR)/main.c
CONV_SRC		= $(SRC_DIR)/conversion.c
DEBUG_SRC		= $(SRC_DIR)/debug.c
MEMORY_SRC		= $(SRC_DIR)/memory.c
PROJ1_SRC		= $(SRC_DIR)/project1.c
REVERSE_SRC		= $(SRC_DIR)/reverse.c
CIRBUF_SRC		= $(SRC_DIR)/cirbuf.c
UART_SRC		= $(SRC_DIR)/uart.c
PROJ2_SRC		= $(SRC_DIR)/project2.c
KL25Z_SYS_SRC	= $(SRC_DIR)/system_MKL25Z4.c
KL25Z_SUP_SRC	= $(SRC_DIR)/startup_MKL25Z4.S

# Include Directory
INC_CMN_DIR 	= $(INC_DIR)/common
CMN_INC			= $(INC_CMN_DIR)/common.h
CONV_INC	 	= $(INC_CMN_DIR)/conversion.h
DEBUG_INC 		= $(INC_CMN_DIR)/debug.h
MEMORY_INC 		= $(INC_CMN_DIR)/memory.h
PLATFORM_INC	= $(INC_CMN_DIR)/platform.h
PROJ1_INC		= $(INC_CMN_DIR)/project1.h
REVERSE_INC		= $(INC_CMN_DIR)/reverse.h
CIRBUF_INC		= $(INC_CMN_DIR)/cirbuf.h
PROJ2_INC		= $(INC_CMN_DIR)/project2.h

INC_CMSIS_DIR	= $(INC_DIR)/CMSIS
CM0PLUS_INC		= $(INC_CMSIS_DIR)/core_cm0plus.h
CM4_INC			= $(INC_CMSIS_DIR)/core_cm4.h
CM4_SIMD_INC	= $(INC_CMSIS_DIR)/core_cm4_simd.h
CMFUNC_INC		= $(INC_CMSIS_DIR)/core_cmFunc.h
CMINSTR_INC		= $(INC_DMSIS_DIR)/core_cmInstr.h

INC_KL25Z_DIR	= $(INC_DIR)/kl25z
KL25Z_INC		= $(INC_KL25Z_DIR)/MKL25Z4.h
SYS_KL25Z_INC	= $(INC_KL25Z_DIR)/system_MKL25Z4.h
UART_INC		= $(INC_KL25Z_DIR)/uart.h

# Platform Directory
KL25Z_LD		= $(PLATFORM_DIR)/MKL25Z128xxx4_flash.ld

