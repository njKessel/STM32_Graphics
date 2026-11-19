/* 
FILE INFORMATION --------------------
    FILENAME:   gfx02Z1_II.c
    TYPE:       C Header

BLAME&HISTORY -----------------------
    AUTHOR:     Nathaniel Kessel
    DATE:       2026-09-25
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

// Includes
#include <stdint.h>                 // Integer types
#include "st7789v_commands.h"       // Commands for the display's driver chip, Siltronix ST7789V

#define MASK_GPIOD_DAT      0xC003U     // Bit mask for GPIOD data pins
#define MASK_GPIOE_DAT      0x0780U     // Bit mask for GPIOE data pins

#define MASK_GPIOE_DCX      0x0010U     // Bit mask for the data/command select pin @ PE4
#define MASK_GPIOD_CS       0x0080U     // Bit mask for the chip select pin @ PD7
#define MASK_GPIOD_W        0x0020U     // Bit mask for the write enable pin @ PD5

// Enables
void display_IO_ChipSelect(void);

// Data Write
void display_IO_WriteReg(uint16_t reg);
void display_IO_WriteDat(uint16_t data);

void displayInit();
void display_IO_Init();

void display_CommandSelect(void);
void display_DataSelect(void);

void display_IO_WriteSend(void);
void display_IO_WriteStart(void);

void display_InvertOn(void);
void display_InvertOff(void);
void display_TestPixel(void);