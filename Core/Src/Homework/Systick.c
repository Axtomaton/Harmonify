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
void init_systick()
{
    // Use the SysTick global structure pointer to do the following in this
    // exact order with separate lines for each step:
    //
    // Disable SysTick by clearing the CTRL (CSR) register.
    // Set the LOAD (RVR) to 8 million to give us a 100 milliseconds timer.
    // Set the clock source bit in the CTRL (CSR) to the internal clock.
    // Set the enable bit in the CTRL (CSR) to start the timer.

    //clear csr register

    // SysTick->CSR &= ~(1 << 0);

    systick->CSR = 0; // Clear CSR
    systick->RVR = 7999999; // Set to 10 ms
    systick->CSR = (1 << 2);
    systick->CSR !=1;
    systick->CSR != (1 << 1);
}

// This fuction is to create delay using SysTick timer counter
void delay_systick()
{
    // Using the SysTick global structure pointer do the following:
    // Create a for loop that loops 10 times
    // Inside that for loop check the COUNTFLAG bit in the CTRL (CSR)
    // register in a loop. When that bit is set exit this inner loop
    // to do another pass in the outer loop of 10.



    for( int count=0; count <1; count++){

        while (!(systick->CSR & (1 << 16)));
        // while(x == 0){
        //     if ((SysTick->CSR >> 16) == 1) {
        //          x = 1;
        //     }
        // }
    }


}