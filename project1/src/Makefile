#############################################################
#															#
# @file Makefile											#
# @brief A main Makefile for building the project1 system	#
#															#
# @author Brian Kelly										#
# @date September 23, 2017									#
#															#
#############################################################

include sources.mk

EXECUTABLE = project1.elf
MAP_FILE = project1.map

SOURCES += $(MAIN_SRC)

ifeq ($(PLATFORM),KL25Z)
SOURCES += $(KL25Z_SYS_SRC) 
ASM_SRC = $(KL25Z_SUP_SRC)
endif

INCLUDES += -I$(INC_CMN_DIR) 

ifeq ($(PLATFORM),KL25Z)
INCLUDES += -I$(INC_CMSIS_DIR) \
			-I$(INC_KL25Z_DIR)
endif

OBJECTS = $(SOURCES:.c=.o)
ASM_OBJ = $(ASM_SRC:.S=.o)
SRC_DEP = $(SOURCES:.c=.d)
ASM_DEP = $(ASM_SRC:.S=.d)

# For Building the library directory
AR = ar -rvc
LIBRARY = $(LIB_DIR)/libproject1.a
LIB_SRC := $(CONV_SRC) \
			$(DEBUG_SRC) \
			$(MEMORY_SRC) \
			$(PROJ1_SRC) \
			$(REVERSE_SRC)	

LIB_OBJ = $(LIB_SRC:.c=.o)
LIB_DEP = $(LIB_SRC:.c=.d)

# Default compiler if the user doesn't specify the PLATFORM
CC=gcc

# Specify platforms for those variables
ifeq ($(PLATFORM),HOST) 
CC = gcc
CODE_SIZE = size -B
LD = ld
LD_ARCH = elf_x86_64
LD_ARCH_DIR = /usr/lib/x86_64-linux-gnu/
endif

ifeq ($(PLATFORM),BBB)
CC = arm-linux-gnueabihf-gcc
CODE_SIZE = arm-linux-gnueabihf-size -B
LD = arm-linux-gnueabihf-ld
LD_ARCH = armelf_linux_eabi
endif

ifeq ($(PLATFORM),KL25Z)
CC = arm-none-eabi-gcc
CPU = cortex-m0plus
ARCH = armv6-m
FLOAT = soft
FPU = fpv4-sp-d16
SPECS = nosys.specs
CODE_SIZE = arm-none-eabi-size -B
LD = arm-none-eabi-ld 
LD_ARCH = armelf
endif

CFLAGS = -g \
		-std=c99 \
		-Wall \
		-Werror \
		-O0 

CPPFLAGS += -DPROJECT1
		
ifeq ($(PLATFORM),HOST)
CPPFLAGS += -DVERBOSE 
endif
ifeq ($(PLATFORM),BBB)
CPPFLAGS += -DVERBOSE
endif

DEPFLAGS += -MD \
			-MP

ifeq ($(PLATFORM),KL25Z)
CC_LDFLAGS += -T$(KL25Z_LD)
endif

CC_LDFLAGS += -L$(LIB_DIR)\
           -lproject1 \
		   -Xlinker -Map=$(MAP_FILE)

ifeq ($(PLATFORM),KL25Z)
LD_LDFLAGS += -T$(KL25Z_LD)
endif

LD_LDFLAGS += \
           -lproject1 \
		   -m $(LD_ARCH) \
		   -Map=$(MAP_FILE) \
		   -N \
		   -r \
		   -s 

PLATFORM_FLAGS += -mcpu=$(CPU) \
				  -mthumb \
				  -march=$(ARCH) \
				  -mfloat-abi=$(FLOAT) \
		          -mfpu=$(FPU) \
		          --specs=$(SPECS)

.PHONY: build compile-all build-lib
.PHONY: clean

ifeq ($(PLATFORM),KL25Z)
build: compile-all build-lib
	@echo;
	@echo "##################### Linking ... $@ target on $(PLATFORM) ########################"
	@echo;
#	$(LD) $(LD_LDFLAGS) -o $(EXECUTABLE) $(OBJECTS) $(ASM_OBJ)
	$(CC) $(PLATFORM_FLAGS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $(EXECUTABLE) $(OBJECTS) $(ASM_OBJ) $(CC_LDFLAGS)
	$(CODE_SIZE) $(EXECUTABLE) 

%.i: %.c
	@echo;
	@echo "##################### Producing $@ file on $(PLATFORM) ########################"
	@echo;
	$(CC) $(PLATFORM_FLAGS) $(CFLAGS) $(CPPFLAGS) -E $(INCLUDES) $< > $@ 

%.asm: %.c
	@echo;
	@echo "##################### Producing $@ file on $(PLATFORM) ########################"
	@echo;
	$(CC) $(PLATFORM_FLAGS) $(CFLAGS) $(CPPFLAGS) -S $(INCLUDES) $< -o $@

%.o: %.c 
	@echo;
	@echo "##################### Producing $@ file on $(PLATFORM) ########################"
	@echo;
	$(CC) $(PLATFORM_FLAGS) $(CFLAGS) $(CPPFLAGS) -c $< $(INCLUDES)

compile-all: $(SOURCES) $(ASM_SRC) $(LIB_SRC)
	@echo;
	@echo "##################### Compiling ... $@ target on $(PLATFORM) ########################"
	@echo;
	$(CC) $(PLATFORM_FLAGS) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c $(SOURCES) $(ASM_SRC) $(LIB_SRC) $(INCLUDES)

else
build: compile-all build-lib
	@echo;
	@echo "##################### Linking ... $@ target on $(PLATFORM) ########################"
	@echo;
#	$(LD) $(LD_LDFLAGS) -o $(EXECUTABLE) $(OBJECTS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $(EXECUTABLE) $(OBJECTS) $(CC_LDFLAGS)
	$(CODE_SIZE) $(EXECUTABLE)  

%.i: %.c
	@echo;
	@echo "##################### Producing $@ file on $(PLATFORM) ########################"
	@echo;
	$(CC) $(CFLAGS) $(CPPFLAGS) -E $(INCLUDES) $< > $@ 

%.asm: %.c
	@echo;
	@echo "##################### Producing $@ file on $(PLATFORM) ########################"
	@echo;
	$(CC) $(CFLAGS) $(CPPFLAGS) -S $(INCLUDES) $< -o $@

%.o: %.c 
	@echo;
	@echo "##################### Producing $@ file on $(PLATFORM) ########################"
	@echo;
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES)

compile-all: $(SOURCES) $(LIB_SRC)
	@echo;
	@echo "##################### Compiling ... $@ target on $(PLATFORM) ########################"
	@echo;
	$(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c $(SOURCES) $(LIB_SRC) $(INCLUDES)

endif
build-lib: $(LIB_OBJ)
	@echo;
	@echo "##################### Building Library ... $@ target on $(PLATFORM) ########################"
	@echo;
	@mkdir -p $(LIB_DIR)
	$(AR) $(LIBRARY) $(LIB_OBJ)   

clean:
	@echo;
	@echo "##################### Cleaning up ... ########################"
	@echo;
	rm -rf *.i *.asm *.o *.d *.map $(EXECUTABLE) $(LIB_DIR) *.a

-include $(SRC_DEP) $(ASM_DEP) $(LIB_DEP)

