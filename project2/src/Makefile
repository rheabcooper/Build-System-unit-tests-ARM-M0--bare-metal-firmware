#############################################################
#															#
# @file Makefile											#
# @brief A main Makefile for building the project1 system	#
#															#
# This Makefile was all developed by Brian Kelly.			#	
#															#
# @author Brian Kelly										#
# @date October 24, 2017									#
#															#
#############################################################

include sources.mk

SOURCES += $(MAIN_SRC)

ifeq ($(PLATFORM),KL25Z)
SOURCES += $(KL25Z_SYS_SRC) \
		   $(UART_SRC) 
ASM_SRC = $(KL25Z_SUP_SRC)
endif

INCLUDES += -I$(INC_CMN_DIR) 

ifeq ($(PLATFORM),KL25Z)
INCLUDES += -I$(INC_CMSIS_DIR) \
			-I$(INC_KL25Z_DIR)
endif

OBJECTS_PATH = $(SOURCES:.c=.o)
OBJECTS = $(addprefix $(OBJ_DIR)/,$(notdir $(OBJECTS_PATH)))
ASM_OBJ_PATH = $(ASM_SRC:.S=.o)
ASM_OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(ASM_OBJ_PATH)))
SRC_DEP_PATH = $(SOURCES:.c=.d)
SRC_DEP = $(addprefix $(DEP_DIR)/,$(notdir $(SRC_DEP_PATH)))
ASM_DEP_PATH = $(ASM_SRC:.S=.d)
ASM_DEP = $(addprefix $(DEP_DIR)/,$(notdir $(ASM_DEP_PATH)))

# For building the library directory
AR = ar -rvc
LIBRARY = $(LIB_DIR)/libproject1.a
LIB_SRC := $(CONV_SRC) \
			$(DEBUG_SRC) \
			$(MEMORY_SRC) \
			$(PROJ1_SRC) \
			$(REVERSE_SRC) \
			$(CIRBUF_SRC) \
			$(PROJ2_SRC)	

LIB_OBJ_PATH = $(LIB_SRC:.c=.o)
LIB_OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(LIB_OBJ_PATH)))
LIB_DEP_PATH = $(LIB_SRC:.c=.d)
LIB_DEP = $(addprefix $(DEP_DIR)/,$(notdir $(LIB_DEP_PATH)))

# For building the test directory
TEST_SRC := $(CONV_TEST) \
			$(MEM_TEST) \
			$(CIRBUF_TEST)

TEST_OBJ = $(TEST_SRC:%.c=%.o)

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

ifeq ($(MAIN),PROJECT1)
EXECUTABLE = project1.elf
MAP_FILE = project1.map
CPPFLAGS += -DPROJECT1
endif
ifeq ($(MAIN),PROJECT2)
EXECUTABLE = project2.elf
MAP_FILE = project2.map
CPPFLAGS += -DPROJECT2
endif
		
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

CC_LDFLAGS += -L$(LIB_DIR) \
           -lproject1 \
		   -Xlinker -Map=$(MAP_FILE)

ifeq ($(PLATFORM),KL25Z)
LD_LDFLAGS += -T$(KL25Z_LD)
endif

LD_LDFLAGS += -L$(LIB_DIR) \
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

POSTCOMPILE = @mv $(OBJ_DIR)/*.d $(DEP_DIR)/.

.PHONY: build compile-all build-lib
.PHONY: clean

ifeq ($(PLATFORM),KL25Z)
build: compile-all build-lib
	@echo;
	@echo "##################### Linking ... $@ target on $(PLATFORM) ########################"
	@echo;
#	$(LD) $(LD_LDFLAGS) $(INCLUDE) -o $(EXECUTABLE) $(OBJECTS) $(ASM_OBJ)
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
	@mkdir -p $(OBJ_DIR)
	$(CC) $(PLATFORM_FLAGS) $(CFLAGS) $(CPPFLAGS) -c $< $(INCLUDES) -o obj/$@

compile-all: $(SOURCES) $(ASM_SRC) $(LIB_SRC)
	@echo;
	@echo "##################### Compiling ... $@ target on $(PLATFORM) ########################"
	@echo;
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	cd $(OBJ_DIR) && \
	$(CC) $(PLATFORM_FLAGS) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c $(SOURCES) $(ASM_SRC) $(LIB_SRC) $(INCLUDES)
	$(POSTCOMPILE)

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
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $(OBJ_DIR)/$@

compile-all: $(SOURCES) $(LIB_SRC)
	@echo;
	@echo "##################### Compiling ... $@ target on $(PLATFORM) ########################"
	@echo;
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	cd $(OBJ_DIR) && \
	$(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c $(SOURCES) $(LIB_SRC) $(INCLUDES) 
	$(POSTCOMPILE)
endif

build-lib: $(LIB_OBJ)
	@echo;
	@echo "##################### Building Library ... $@ target on $(PLATFORM) ########################"
	@echo;
	@mkdir -p $(LIB_DIR)
	$(AR) $(LIBRARY) $(LIB_OBJ)   

ifeq ($(PLATFORM),BBB)
# Target Functionality:  copy to the BBB's OS and execute it remotely.  
.PHONY: upload build
upload: build
	@scp $(SRC_DIR)/$(EXECUTABLE) $(BBB_ROOT):$(BBB_USER_BIN)
	@ssh $(BBB_ROOT) -X $(BBB_USER_BIN)/$(EXECUTABLE)
endif

ifeq ($(PLATFORM),HOST)
# Target Functionality: build and run the unit tests using the cmocka framework.  
.PHONY: unittests 

cmocka:

unittests: 
	
endif

.PHONY: clean
clean:
	@echo;
	@echo "##################### Cleaning up ... ########################"
	@echo;
	rm -rf *.i *.asm $(OBJ_DIR) $(DEP_DIR) *.map *.elf $(LIB_DIR)

-include $(SRC_DEP) $(ASM_DEP) $(LIB_DEP)

