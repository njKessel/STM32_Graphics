/* 
FILE INFORMATION --------------------
    FILENAME:   ST7789V_commands.c
    TYPE:       C Driver

BLAME&HISTORY -----------------------
    AUTHOR:     Nathaniel Kessel
    DATE:       2026-09-23
    SOURCES:    Sitronix ST7789V Datasheet sourced from https://dl.espressif.com/dl/schematics/ST7789V_SPEC_V1.0.pdf
                https://github.com/STMicroelectronics/stm32-ili9341/blob/main/ili9341.h for style and driver research
                https://github.com/STMicroelectronics/stm32-bsp-common/blob/main/lcd.h

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
    This file contains the commands used for interfacing with Sitronix' ST7789V.
    This is the display driver used on the X-NUCLEO board for this project, you
    can find the datasheet for this driver above in BLAME&HISTORY/SOURCES
*/

#include "st7789v_commands.h"

void ST7789V_Init() {
    
}

// Display power on/off
void ST7789V_DispOn() {
    
}
void ST7789V_DispOff() {

}