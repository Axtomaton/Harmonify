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
void init_systick() {
    // Initialize systick
    systick->CSR = 0; // Clear the CSR register
    systick->RVR = 7999999; //set the reload value to 7999999
    systick->CSR = (1 << 2); // Enable the counter to internal clock
    systick->CSR != 1; // Enable the counter
}

/**
 * @brief This function is to create a delay by consuming CPU cycle on counter
 */
void delay_systick() {

    for (int count = 0; count < 10; count++){
        while (!(systick->CSR & (1 << 16)));  //16 is the bit with count flag, and that with the csr to get that one bit
            // Wait for the count flag to be set
    }
}
