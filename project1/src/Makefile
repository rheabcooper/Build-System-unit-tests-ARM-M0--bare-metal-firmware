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
LD_ENTRY = main
endif

ifeq ($(PLATFORM),BBB)
CC = arm-linux-gnueabihf-gcc
CODE_SIZE = arm-linux-gnueabihf-size -B
LD = arm-linux-gnueabihf-ld 
LD_ENTRY = main
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
LD_ENTRY = Reset_Handler
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
LDFLAGS += -T$(KL25Z_LD)
endif

LDFLAGS += -L$(LIB_DIR) \
           -lproject1 \
		   -Map=$(MAP_FILE) \
		   -e $(LD_ENTRY) \
	       -N \
		   -r

PLATFORM_FLAGS += -mcpu=$(CPU) \
				  -mthumb \
				  -march=$(ARCH) \
				  -mfloat-abi=$(FLOAT) \
		          -mfpu=$(FPU) \
		          --specs=$(SPECS)

ifeq ($(PLATFORM),KL25Z)
.PHONY: build comiple-all build-lib
build: compile-all build-lib
	$(LD) $(LDFLAGS) -o $(EXECUTABLE) $(OBJECTS) $(ASM_OBJ)
	$(CODE_SIZE) $(EXECUTABLE) 

%.i: %.c
	$(CC) $(PLATFORM_FLAGS) $(CFLAGS) $(CPPFLAGS) -E $(INCLUDES) $< > $@ 

%.asm: %.c
	$(CC) $(PLATFORM_FLAGS) $(CFLAGS) $(CPPFLAGS) -S $(INCLUDES) $< -o $@

%.o: %.c 
	$(CC) $(PLATFORM_FLAGS) $(CFLAGS) $(CPPFLAGS) -c $< $(INCLUDES)

.PHONY: compile-all
compile-all: $(SOURCES) $(ASM_SRC) $(LIB_SRC)
	$(CC) $(PLATFORM_FLAGS) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c $(SOURCES) $(ASM_SRC) $(LIB_SRC) $(INCLUDES)

else
.PHONY: build compile-all build-lib
build: compile-all build-lib
	$(LD) $(LDFLAGS) -o $(EXECUTABLE) $(OBJECTS)
	$(CODE_SIZE) $(EXECUTABLE)  

%.i: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -E $(INCLUDES) $< > $@ 

%.asm: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -S $(INCLUDES) $< -o $@

%.o: %.c 
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES)

.PHONY: compile-all
compile-all: $(SOURCES) $(LIB_SRC)
	$(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c $(SOURCES) $(LIB_SRC) $(INCLUDES)

endif
.PHONY: build-lib
build-lib: $(LIB_OBJ)
	$(AR) $(LIBRARY) $(LIB_OBJ)   

.PHONY: clean
clean:
	rm -f *.i *.asm *.o *.d *.map $(EXECUTABLE) $(LIB_DIR)/*.a

-include $(SRC_DEP) $(ASM_DEP) $(LIB_DEP)

