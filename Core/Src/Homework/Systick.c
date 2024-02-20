/**
 * @file Systick.c
 * @author Ivan lin - il9082@rit.edu
 * @brief Homework 4
 * @date 2024-02-19 
 */

#include "Systick.h"
#include <stdint.h>

// Define systick instance
struct systick* systick = (struct systick*) 0xE000E010; // Systick base address

/**
 * @brief Initialization function for systick
 * 
 * @return struct systick* 
 */
struct systick * init_systick() {
    // Initialize systick
    systick->CSR &= ~(1 << 0); // Clear the CSR register
    systick->CSR |= 1 << 2;    // Set the internal clock source
    systick->CSR |= 1;    // Enable the systick counter
    systick->RVR = 15999999;  // Set the reload value for 2 seconds delay
    return systick;
}

/**
 * @brief This function is to create a delay by consuming CPU cycle on counter
 */
void delay_systick() {
    // Wait until the count flag counts down to 0. 
    while ((systick->CSR >> 16) == 0) { // Check the count flag bit to make sure the counter is not 1
        // Wait
    }
}
