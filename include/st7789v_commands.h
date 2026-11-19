/* 
FILE INFORMATION --------------------
    FILENAME:   ST7789V_commands.h
    TYPE:       C Header

BLAME&HISTORY -----------------------
    AUTHOR:     Nathaniel Kessel
    DATE:       2026-09-22
    SOURCES:    Sitronix ST7789V Datasheet sourced from https://dl.espressif.com/dl/schematics/ST7789V_SPEC_V1.0.pdf
                https://github.com/STMicroelectronics/stm32-ili9341/blob/main/ili9341.h for style and driver research
                https://github.com/STMicroelectronics/stm32-bsp-common/blob/main/lcd.h

LLM USAGE ---------------------------
    AI USE:     No
    TYPE:       N/A
    UPDATED:    2026-09-22
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

#ifndef ST7789V_COMMANDS_H
#define ST7789V_COMMANDS_H

// Includes
#include <stdint.h>
#include "gfx02z1_II.h"

// Screen Size
//      Direction           Size            Size in pixels
#define ST7789V_HZ_DISP     ((uint16_t)     340)
#define ST7789V_VT_DISP     ((uint16_t)     240)

// Timings
//      Name                Data Size       Timing Length       Unit
#define ST7789V_HZ_SYNC     ((uint16_t)     9)                  // Clock Cycles
#define ST7789V_HZ_BP       ((uint16_t)     9)                  // Clock Cycles
#define ST7789V_HZ_FP       ((uint16_t)     38)                 // Clock Cycles
#define ST7789V_VT_SYNC     ((uint16_t)     4)                  // Lines
#define ST7789V_VT_BP       ((uint16_t)     4)                  // Lines
#define ST7789V_VT_FP       ((uint16_t)     8)                  // Lines

// Maps 8-bit command 0b76543210 -> 16-bit GPIO pin layout 0b10xxx7654xxxxx32 at compile time
#define ST7789V_MAP(x)                  ((((x) & 0x03U) << 14) | (((x) & 0xF0U) << 3) | (((x) & 0x0CU) >> 2))

// Commands and Operations
//      Command Name                    Code (unsigned)         Description
#define ST7789V_NOP                     ST7789V_MAP(0x00U)      // No operation, wastes a cycle
#define ST7789V_SWRESET                 ST7789V_MAP(0x01U)      // Software reset
#define ST7789V_RDDID                   ST7789V_MAP(0x04U)      // Read display IO TODO: What does this return
#define ST7789V_RDDST                   ST7789V_MAP(0x09U)      // Read display status TODO: What does this return
#define ST7789V_RDDPM                   ST7789V_MAP(0x0AU)      // Read display power status TODO: What does this return
#define ST7789V_RDD_MADCTL              ST7789V_MAP(0x0BU)      // Read display TODO: What does this return
#define ST7789V_RDD_COLMOD              ST7789V_MAP(0x0CU)      // Read display pixel TODO: What does this return
#define ST7789V_RDDIM                   ST7789V_MAP(0x0DU)      // Read display image TODO: What does this return
#define ST7789V_RDDSM                   ST7789V_MAP(0x0EU)      // Read display signal TODO: What does this return
#define ST7789V_RDDSDR                  ST7789V_MAP(0x0FU)      // Read self-diag result TODO: how do i trigger self-test
#define ST7789V_SLPIN                   ST7789V_MAP(0x10U)      // Sleep in
#define ST7789V_SLPOUT                  ST7789V_MAP(0x11U)      // Sleep out
#define ST7789V_PTLON                   ST7789V_MAP(0x12U)      // Partial mode enable TODO: What is partial mode
#define ST7789V_NORON                   ST7789V_MAP(0x13U)      // Partial mode off
#define ST7789V_INVOFF                  ST7789V_MAP(0x20U)      // Display inversion off
#define ST7789V_INVON                   ST7789V_MAP(0x21U)      // Display inversion on
#define ST7789V_GAMSET                  ST7789V_MAP(0x26U)      // Gamma set TODO: how is this different than #define ST7789V_INVON
#define ST7789V_DISPOFF                 ST7789V_MAP(0x28U)      // Display OFF
#define ST7789V_DISPON                  ST7789V_MAP(0x29U)      // Display ON
#define ST7789V_CASET                   ST7789V_MAP(0x2AU)      // Column address set
#define ST7789V_RASET                   ST7789V_MAP(0x2BU)      // Row address set
#define ST7789V_RAMWR                   ST7789V_MAP(0x2CU)      // Memory write
#define ST7789V_RAMRD                   ST7789V_MAP(0x2EU)      // Memory read
#define ST7789V_PTLAR                   ST7789V_MAP(0x30U)      // Partial start/end addr set (datasheet says sart, assumed typo?)
#define ST7789V_VSCRDEF                 ST7789V_MAP(0x33U)      // Vertical scrolling definition
#define ST7789V_TEOFF                   ST7789V_MAP(0x34U)      // Tearing off
#define ST7789V_TEON                    ST7789V_MAP(0x35U)      // Tearing on
#define ST7789V_MADCTL                  ST7789V_MAP(0x36U)      // Memory data access control
#define ST7789V_VSCRSADD                ST7789V_MAP(0x37U)      // Vertical scroll start addr
#define ST7789V_IDMOFF                  ST7789V_MAP(0x38U)      // Idle mode off
#define ST7789V_IDMON                   ST7789V_MAP(0x39U)      // Idle mode on
#define ST7789V_COLMOD                  ST7789V_MAP(0x3AU)      // Interface pixel format
#define ST7789V_RAMWRC                  ST7789V_MAP(0x3CU)      // Memory write continue
#define ST7789V_RAMRDC                  ST7789V_MAP(0x3EU)      // Memory read continue
#define ST7789V_TESCAN                  ST7789V_MAP(0x44U)      // Set tear scanline
#define ST7789V_RDTESCAN                ST7789V_MAP(0x45U)      // Get scanline
#define ST7789V_WRDISBV                 ST7789V_MAP(0x51U)      // Write display brigtness
#define ST7789V_RDDISBV                 ST7789V_MAP(0x52U)      // Read display brightness
#define ST7789V_WRCTRLD                 ST7789V_MAP(0x53U)      // Write control display TODO: what is control display
#define ST7789V_RDCTRLD                 ST7789V_MAP(0x54U)      // Read control diplay value
#define ST7789V_WRCACE                  ST7789V_MAP(0x55U)      // Write content adaptive brightness control, color enhancement
#define ST7789V_RDCABC                  ST7789V_MAP(0x56U)      // Read content adaptive brightness control
#define ST7789V_WRCABCMB                ST7789V_MAP(0x5EU)      // Write CABC minimum brightness TODO: what is CABC
#define ST7789V_RDCABCMD                ST7789V_MAP(0x5FU)      // read CABC minimum brightness
#define ST7789V_RDABCSDR                ST7789V_MAP(0x68U)      // Read auto brightness self-test
#define ST7789V_RDID1                   ST7789V_MAP(0xDAU)      // Read ID1
#define ST7789V_RDID2                   ST7789V_MAP(0xDBU)      // Read ID2
#define ST7789V_RDID3                   ST7789V_MAP(0xDCU)      // Read ID3

// Display Functions
void        ST7789V_Init();
void        ST7789V_DispOn();
void        ST7789V_DispOff();
void        ST7789V_InvertOn();
void        ST7789V_InvertOff();
void        ST7789V_TestPixel();

// IO functions
void        ST7789V_IO_WriteData(uint16_t Data);
void        ST7789V_IO_WriteRegister(uint16_t Register);
void        ST7789V_IO_ReadData(uint8_t RegValue, uint8_t ReadSize); // TODO: check sizes
void        ST7789V_IO_CS(void);

#endif