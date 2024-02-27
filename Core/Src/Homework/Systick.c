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
// This fuction is to create delay using SysTick timer counter
void delay_systick() {
    // Using the SysTick global structure pointer do the following:
    // Create a for loop that loops 10 times
    for (int i = 0; i < 1; i++) {
        // Inside that for loop check the COUNTFLAG bit in the CTRL (CSR)
        // register in a loop. When that bit is set exit this inner loop
        while ((systick->CSR & (1 << 16)) == 0) {
            // do nothing
        }
    // to do another pass in the outer loop of 10.
    }
}



