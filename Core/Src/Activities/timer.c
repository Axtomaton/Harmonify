/**
 * @file timer.c
 * @author Ivan Lin -il9082@rit.edu
 * @date 2024-02-13 
 */
#include <stdint.h>
#include "printf.h"

// Define a struct for the systick timer

struct systick {
    uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;
};

void print_systick(){
    
    struct systick* stick = (struct systick*) 0xE000E010;
    stick->CSR |= 1 << 2; //Set the internal clock
    stick->CSR |= 1; //Turn on
    // stick->CSR = 1;
    stick->RVR = 79999999;

    printf("%ld\n", stick->CSR);
    printf("%ld\n", stick->RVR);
    printf("%ld\n", stick->CVR);
    printf("%ld\n", stick->CALIB);

    int count = 0;
    while (1){
        if ((stick->CSR & (1 << 16)) > 0){
            count++;
            printf("%31d\r", count / 10);
        }
    }

}
