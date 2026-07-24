// TOOLCHAIN EXECUTABLES
CC = arm-none-eabi-gcc // For C compilation
OBJCOPY = arm-none-eabi-objcopy // For converting object files to binary
SIZE = arm-none-eabi-size // For displaying the size of the compiled binary

// MCU Arch
MCU = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-16