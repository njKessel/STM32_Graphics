/* 
FILE INFORMATION --------------------
    FILENAME:   main.c
    TYPE:       C Source

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
    This file contains the main logic for the project.
*/

// INCLUDES
#include <stdint.h>                 // Integer library, primarily for uintx_t
#include "stm32f4xx.h"              // Device Peripheral Access Layer Router
#include "gfx02z1_II.h"             // X-NUCLEO-GFX02Z1 Revision 2 custom driver

int main() {
    displayInit();                  // Initialize ST7789V LCD Driver and X-NUCLEO display

    while(1) {                      // Temporary no-operation loop to prevent crashing
        __NOP();
    }
}