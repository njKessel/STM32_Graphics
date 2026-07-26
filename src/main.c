#include <stdint.h>
#include "stm32f4xx.h"

int main(void) {
    // Enable GPIOB
    RCC->AHB1ENR |= (1 << 1);

    // Reset GPIO modes
    GPIOB->MODER &= ~(0b11 << 0);       // PB0
    GPIOB->MODER &= ~(0b11 << 14);      // PB7
    GPIOB->MODER &= ~(0b11 << 28);      // PB14

    // Set GPIO modes for write
    GPIOB->MODER |= (0b01 << 0);        // PB0
    GPIOB->MODER |= (0b01 << 14);       // PB7
    GPIOB->MODER |= (0b01 << 28);       // PB14

    volatile uint8_t cycleCounter = 0;

    while (1) {
        cycleCounter += 1;

        // Enable LED LD1
        GPIOB->ODR |= (1 << 0);
        // Disable LED LD2
        GPIOB->ODR &= ~(1 << 7);
        // Enable LED LD3
        if (cycleCounter % 2 = 0) {
            GPIOB->ODR |= (1 << 14);
        }

        for (volatile uint32_t i = 0; i < 1000000; i++) {
            // Delay
        }

        // Disable LED LD1
        GPIOB->ODR &= ~(1 << 0);
        // Enable LED LD2
        GPIOB->ODR |= (1 << 7);
        // Disable LED LD3
        GPIOB->ODR &= ~(1 << 14);

        for (volatile uint32_t i = 0; i < 1000000; i++) {
            // Delay
        }
    }
}