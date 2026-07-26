#include <stdint.h>
#include "stm32f4xx.h"

int main(void) {
    // Enable GPIOB
    RCC->AHB1ENR |= (1 << 1);

    // Reset GPIO mode
    GPIOB->MODER &= ~(0b11 << 0);

    // Set GPIO mode for write
    GPIOB->MODER |= (0b01 << 0);

    while (1) {
        // Enable LED LD1
        GPIOB->ODR |= (1 << 0);

        for (volatile uint32_t i = 0; i < 1000000; i++) {
            // Delay
        }

        // Disable LED LD1
        GPIOB->ODR &= ~(1 << 0);

        for (volatile uint32_t i = 0; i < 1000000; i++) {
            // Delay
        }
    }
}