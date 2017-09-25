#############################################################
#															#
# @file Makefile											#
# @brief A main Makefile for building the project1 system	#
#															#
# @author Brian Kelly										#
# @date September 23, 2017									#
#															#
#############################################################

#include sources.mk
include standard_macro.txt

ifeq ($(PLATFORM),HOST) 
CC = gcc
endif
ifeq ($(PLATFORM),BBB)
CC = arm-linux-gnueabihf-gcc
endif
ifeq ($(PLATFORM),KL25Z)
CC = arm-none-eabi-gcc

TARGET_ARCH = -mcpu=cortex-m0plus \
		    -mthumb \
		    -march=armv6-m \
		    -mfloat-abi=softfp \
		    -mfpu=fpv4-sp-d16 \
		    --specs=nosys.specs
endif

CFLAGS = -g \
		-std=c99 \
		-Wall \
		-Werror \
		-O0 

CPPFLAGS = -DVERBOSE \
		   -DPROJECT1 

LDFLAGS = -static \
		  -L$(SRC_DIR) \
		  -lproj 
		  
SOURCES = $(MAIN_SRC)

INCLUDES = -I$(INC_CMN_DIR)

AR = ar rc
LIBRARY = libproj.a

OBJDIR = obj

build: main.o build-lib
	$(CC)  $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) $(INCLUDES) $(LDFLAGS) -o project1.elf

#%.i: %.c
#	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -E %.c -o %.i

#%.asm: $(SOURCES)
#	$(CC) $(CFLAGS) -S $(SOURCES)

main.o: 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c $(INCLUDES) $(SOURCES) $(LIB_DIR)/*.c 

build-lib:
	$(AR) $(LIBRARY) *.o  

#compile-all:

run: build
	./project1.elf

clean:
	-rm -f *.o *.a *.elf
