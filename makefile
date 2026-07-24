# TOOLCHAIN EXECUTABLES
CC = arm-none-eabi-gcc 											# For C compilation
OBJCOPY = arm-none-eabi-objcopy 								# For converting object files to binary
SIZE = arm-none-eabi-size 										# For displaying the size of the compiled binary

# MCU Arch
MCU = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-16 # Cortex-M4 cores with Thumb-2 ISA, routing math to strictly the FPU.

# Where to find headers
INCLUDES = -Iinclude -Ivendor/cmsis								# Telling Make that the #include files are in the include and cmsis directories

# Where to find source
C_SOURCES = \
src/main.c \
src/system.stm32f4xx.c

