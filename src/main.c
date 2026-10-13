#include <stdint.h>
#include "stm32f4xx.h"
#include "gfx02z1_II.h"

int main() {
    displayInit();

    while(1) {
        __NOP();
    }
}