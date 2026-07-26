# TOOLCHAIN EXECUTABLES
CC = arm-none-eabi-gcc 												# For C compilation
OBJCOPY = arm-none-eabi-objcopy 									# For converting object files to binary
SIZE = arm-none-eabi-size 											# For displaying the size of the compiled binary

# MCU Arch
MCU = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 	# Cortex-M4 cores with Thumb-2 ISA, routing math to strictly the FPU.

# Where to find headers
INCLUDES = -Iinclude -Ivendor/cmsis									# Telling Make that the #include files are in the include and cmsis directories

# Where to find source
C_SOURCES = \
src/main.c \
src/system_stm32f4xx.c

# Assembly startup file
ASM_SOURCES = startup/startup_stm32f412zx.s

# C Compiler flags
CFLAGS = $(MCU) $(INCLUDES) -Wall -Os -MMD -MP -DSTM32F412Zx -H		# Pass MCU and INCLUDES variables to the C compiler, show all warnings (-Wall) and optimize for size (-Os), -MMD and -MP handle dependencies 

# Linker Directives
LDSCRIPT = STM32F412ZG_FLASH.ld										# Point to linker script
LDFLAGS = $(MCU) -T$(LDSCRIPT) -Wl,--gc-sections --specs=nano.specs # Pass MCU variables so it knows what its assembling, tell it where to find linker file, enable garbage collection, use lightweight C lib

# Create the object files
OBJECTS = $(addprefix build/,$(notdir $(C_SOURCES:.c=.o)))			# Replace file extension .c with .o, remove the directory path, move it to the build directory
OBJECTS += $(addprefix build/,$(notdir $(ASM_SOURCES:.s=.o)))		# Do the same but for assembly

# Tell make where to search for the raw source files
vpath %.c src														# Look for C files in src
vpath %.s startup 													# Look for Assembly files in startup

# Build Rules -------------------------------
all: build/main.elf build/main.bin size								# Tells make it needs build/main.elf, so it figures out how to make it with later rules. Does the same for main.bin, and prints size to terminal using size rule later on.

# C Compilation
# 	Rule for creating files that are in build and are obj files (build/%.o), created from .c files (%.c), and only do this if the build directory exists and wasnt recently modified
# 	Tell the C compiler (CC) to build with flags -c (tells it to compile but not do any linking (thats what LDSCRIPT is for later)), CFLAGS, then $< (whats being handled) and output to $@ (the new file)
build/%.o: %.c | build
	$(CC) -c $(CFLAGS) $< -o $@

# Assembly Compilation
#	Same as C compilation, but pointed at Assembly files, and it ignores optimization and logic since assembly is direct to hardware. It does need to know MCU architecture though
build/%.o: %.s | build
	$(CC) -c $(MCU) $< -o $@

# Invoke the linker
#	Tell the C compiler to link all the object files using the provided linker instructions (flags, LDFLAGS)
build/main.elf: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

# Strip metadata to create the binary
#	Copy main.elf but change it (-O) to binary
build/main.bin: build/main.elf
	$(OBJCOPY) -O binary $< $@

# Show memory footprint in terminal
size: build/main.elf
	$(SIZE) $<

# Create the build directory
build:
	mkdir -p build

# Delete the build directory
clean:
	rm -rf build

# Flash to the start of the chips memory
flash:
	st-flash write build/main.bin 0x08000000

# Dependencies
#	ignore if it doesnt exist, but if there are dependency files created by -MMD -MP then include those rules in this makefile. wildcard tells it to grab any and all .d files, 
-include $(wildcard build/*.d)