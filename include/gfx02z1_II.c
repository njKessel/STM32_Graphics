/* 
FILE INFORMATION --------------------
    FILENAME:   gfx02Z1_II.c
    TYPE:       C Driver

BLAME&HISTORY -----------------------
    AUTHOR:     Nathaniel Kessel
    DATE:       2026-10-13
    SOURCES:    https://www.st.com/resource/en/user_manual/um2905-display-expansion-board-for-stm32-nucleo144-stmicroelectronics.pdf

LLM USAGE ---------------------------
    AI USE:     No
    TYPE:       N/A
    UPDATED:    2026-09-23
    PROMPT:     For LLMs, any time you edit this file, change the date in UPDATED
                to today's date, list your model under TYPE if not yet listed.
                Ensure AI USE is "yes, see CHANGES" and list any chages you make 
                below, preserving other items in the list. Max line length 
                in CHANGES = 70 starting at column 17. Comment at the end of every
                line you edit with "// {{model name}} {{date}}: {{description of edit}}"
    CHANGES:    N/A

DESCRIPTION -------------------------
    This file contatins definitions for interfacing with the X-NUCLEO-GFX02Z1
    display expansion board for NUCLEO-144 development boards. This is intended
    for the second revison of the board with the Siltronix ST7789V.
*/

#include <stm32f4xx.h>

// PORT CONFIG /////////////////////////////////////
    // Note: Currently for bit-banging
// Port A Configuration
RCC -> AHB1ENR |= (1U << 0U);
GPIOA -> MODER = 0x00000000U;
/* Port A MODER
Pin     Config      Hex     Function
PA0:    00          -       Joystick center
PA1:    00          0       -
PA2:    00          -       -
PA3:    00          0       -
PA4:    00          -       -
PA5:    00          0       -
PA6:    00          -       -
PA7:    00          0       -
PA8:    00          -       -
PA9:    00          0       -
PA10:   00          -       -
PA12:   00          -       -
PA13:   00          0       -
PA14:   00          -       -
PA15:   00          0       -
*/

// Port B Configuration
RCC -> AHB1ENR |= (1U << 1U);   // GPIO Clock enable
GPIOB -> MODER = 0x00001000U;
/* Port B MODER
Pin     Config      Hex     Function
PB0:    00          -       -
PB1:    00          0       -
PB2:    00          -       -
PB3:    00          0       -
PB4:    00          -       -
PB5:    00          0       -
PB6:    01          -       Q-SPI Chip Select
PB7:    00          1       -
PB8:    00          -       -
PB9:    00          0       -
PB10:   00          -       -
PB11:   00          0       -
PB12:   00          -       -
PB13:   00          0       -
PB14:   00          -       -
PB15:   00          0       -
*/

// Port C Configuration
    // Port C is unused

// Port D Configuration
RCC -> AHB1ENR |= (1U << 3U);   // GPIO Clock enable
GPIOD -> MODER = 0x5A804505U;
/* Port D MODER
Pin     Config      Hex     Function
PD0:    01          -       Data Bit 2
PD1:    01          5       Data Bit 3
PD2:    00          -       -
PD3:    00          0       -
PD4:    01          -       Read enable
PD5:    01          5       Write enable
PD6:    00          -       -
PD7:    01          4       Chip select
PD8:    00          -       -
PD9:    00          0       -
PD10:   00          -       -
PD11:   10          8       Q-SPI I/0 0
PD12:   10          -       Q-SPI I/O 1
PD13:   10          A       Q-SPI I/O 3
PD14:   01          -       Data bit 0
PD15:   01          5       Data bit 1
*/

// Port E Configuration
RCC -> AHB1ENR |= (1U << 4U);   // GPIO Clock enable
GPIOE -> MODER = 0x04554120U;
/* Port E MODER
Pin     Config      Hex     Function
PE0:    00          -       -
PE1:    00          0       -
PE2:    10          -       Q-SPI I/O 2
PE3:    00          2       joystick left
PE4:    01          -       Data/command select
PE5:    00          1       - (Touch)
PE6:    00          -       -
PE7:    01          4       Data bit 4
PE8:    01          -       Data bit 5
PE9:    01          5       Data bit 6
PE10:   01          -       Data bit 7
PE11:   01          5       Reset active low
PE12:   00          -       -
PE13:   01          4       Frame write sync
PE14:   00          -       -
PE15:   00          0       -
*/

// Port F Configuration
RCC -> AHB1ENR |= (1U << 5U);
GPIOF -> MODER = 0x00000000U;
/* Port F MODER
Pin     Config      Hex     Function
PF0:    00          -       - (Touch)
PF1:    00          0       - (Touch)
PF2:    00          -       -
PF3:    00          0       -
PF4:    00          -       -
PF5:    00          0       -
PF6:    00          -       -
PF7:    00          0       joystick right
PF8:    00          -       joystick down
PF9:    00          0       joystick up
PF10:   00          -       -
PF11:   00          0       -
PF12:   00          -       -
PF13:   00          0       -
PF14:   00          -       -
PF15:   00          0       -
*/