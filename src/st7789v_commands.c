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
                https://github.com/adafruit/Adafruit_CircuitPython_ST7789/blob/main/adafruit_st7789.py for init sequence framework

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

extern void delayms(uint32_t ms);

void ST7789V_Init() {
    ST7789V_IO_CS();
    ST7789V_IO_WriteRegister(ST7789V_SWRESET);      // Software reset
    delayms(150);
    ST7789V_IO_WriteRegister(ST7789V_SLPOUT);       // Pull from sleep
    delayms(500);
    ST7789V_IO_WriteRegister(ST7789V_COLMOD);       // Set color depth to 262K 18bit/pixel
    ST7789V_IO_WriteData(ST7789V_MAP(0x06U));
    delayms(10);
    ST7789V_IO_WriteRegister(ST7789V_MADCTL);       
    ST7789V_IO_WriteData(ST7789V_MAP(0x00U));                     // Page addr T>B, column addr L>R, page/column order normal, line addr order T>B, RGB, refresh L>R
    delayms(10);
    // TODO: Delay
    ST7789V_IO_WriteRegister(ST7789V_NORON);        // Normal mode
    delayms(10);
    ST7789V_IO_WriteRegister(ST7789V_DISPON);       // Display on
    delayms(500);
}

// Display power on/off
void ST7789V_DispOn() {
    ST7789V_IO_WriteRegister(ST7789V_DISPON);       // Display on
    delayms(50);
}
void ST7789V_DispOff() {
    ST7789V_IO_WriteRegister(ST7789V_DISPOFF);      // Display off
    delayms(10);
}

void ST7789V_IO_WriteRegister(uint16_t Register){
    display_IO_WriteReg(Register);
}

void ST7789V_IO_WriteData(uint16_t Data) {
    display_IO_WriteDat(Data);
}

void ST7789V_InvertOn() {
    ST7789V_IO_WriteRegister(ST7789V_INVON);
}

void ST7789V_InvertOff() {
    ST7789V_IO_WriteRegister(ST7789V_INVOFF);
}

void ST7789V_IO_CS(void) {
    display_IO_ChipSelect();
    delayms(1);
}

void ST7789V_TestPixel(void) {
    ST7789V_IO_WriteRegister(ST7789V_CASET);
    ST7789V_IO_WriteData(ST7789V_MAP(0x00U));
    ST7789V_IO_WriteData(ST7789V_MAP(0x32U));
    ST7789V_IO_WriteData(ST7789V_MAP(0x00U));
    ST7789V_IO_WriteData(ST7789V_MAP(0x63U));

    ST7789V_IO_WriteRegister(ST7789V_RASET);
    ST7789V_IO_WriteData(ST7789V_MAP(0x00U));
    ST7789V_IO_WriteData(ST7789V_MAP(0x32U));
    ST7789V_IO_WriteData(ST7789V_MAP(0x00U));
    ST7789V_IO_WriteData(ST7789V_MAP(0x63U));

    ST7789V_IO_WriteRegister(ST7789V_RAMWR);
    for (int i = 0; i < 2500; i++) {
        ST7789V_IO_WriteData(ST7789V_MAP(0xFF));
        ST7789V_IO_WriteData(ST7789V_MAP(0x00));
        ST7789V_IO_WriteData(ST7789V_MAP(0x00));
    }
}