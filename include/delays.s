/* 
FILE INFORMATION --------------------
    FILENAME:   delays.s
    TYPE:       Assembly Macros

BLAME&HISTORY -----------------------
    AUTHOR:     Nathaniel Kessel
    DATE:       2026-10-13
    SOURCES:    

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
    This file contains assembly macros for delays on the STM32-F412ZG
*/

// Basic Blocking 1 millisecond delay
.macro          BBDelay1ms              milliseconds
                MOV                     r1, #0                      // 1 / Init counter
                MOVW                    r2, #16000                  // 1 / Init cycles per ms
                MOV                     r3, #8                      // 1 / Init loop divisor
                MOV                     r0, \milliseconds           // 1 / 
                MUL                     r0, r0, r2                  // 1 / Multiply cycles per ms by input ms
                UDIV                    r0, r0, r3                  // 1 / Divide by the number of cycles consumed in the loop
                SUB                     r0, r0, #6                  // 1 / handles this instruction, divide, and one before it 
nopLoop\@:
                NOP                                                 // 1 / Delay, extra to make nice divisor
                NOP                                                 // 1 / Delay, extra to make nice divisor
                NOP                                                 // 1 / Delay
                ADD                     r1, r1, #1                  // 1 / Increment
                CMP                     r1, r0                      // 1 / Check if loop is complete
                BLT                     nopLoop\@                   // 3 / Loop if not
.endm                                                               // 8 Total Cycles
                                                                    // 16000/8 = 200 loops

.global delayms                                                     // Expose to linker
.type delayms, %function                                            // Label as Thumb-2

delayms:
                PUSH                    {r4}                        // Save original value of r4
                BBDelay1ms              r0                          
                POP                     {r4}                        // Restore value of r4
                bx                      lr                          // Branch back to main