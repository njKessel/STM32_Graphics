# TOOLCHAIN EXECUTABLES
CC = arm-none-eabi-gcc 												# For C compilation
OBJCOPY = arm-none-eabi-objcopy 									# For converting object files to binary
SIZE = arm-none-eabi-size 											# For displaying the size of the compiled binary

# MCU Arch
MCU = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-16 	# Cortex-M4 cores with Thumb-2 ISA, routing math to strictly the FPU.

# Where to find headers
INCLUDES = -Iinclude -Ivendor/cmsis									# Telling Make that the #include files are in the include and cmsis directories

# Where to find source
C_SOURCES = \
src/main.c \
src/system.stm32f4xx.c

# Assembly startup file
ASM_SOURCES = startup/startup_stm32f412zx.s

# C Compiler flags
CFLAGS = $(MCU) $(INCLUDES) -Wall -Os								# Pass MCU and INCLUDES variables to the C compiler, show all warnings (-Wall) and optimize for size (-Os)

# Linker Directives
LDSCRIPT = STM32F412ZG_FLASH.ld										# Point to linker script
LDFLAGS = $(MCU) -T$(LDSCRIPT)-Wl,--gc-sections --specs=nano.specs  # Pass MCU variables so it knows what its assembling, tell it where to find linker file, enable garbage collection, use lightweight C lib

# Create the object files
OBJECTS = $(addprefix build/,$(notdir $(C_SOURCES:.c=.o)))			# Replace file extension .c with .o, remove the directory path, move it to the build directory
OBJECTS += $(addprefix build/,$(notdir $(ASM_SOURCES:.s=.o)))		# Do the same but for assembly

# Tell make where to search for the raw source files
vpath %.c src														# Look for C files in src
vpath %.s startup 													# Look for Assembly files in startup