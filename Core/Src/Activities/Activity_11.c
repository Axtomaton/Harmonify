/**
 * @author : Ivan Lin - il9082@rit.edu
 * @date: 03-21-2024
 */

#include "printf.h"
#include "Systick.h"
//use interrupts to make a clock which updates once a second

// Configure the systick
// Initialize Systick
// Handle interruprs
static int count = 0;

int get_time(){
    return count;
}


void SysTick_Handler(){ //hardware runs it for you. m
    count++;
}

void activity_11(){
    init_systick();
    int seconds = 0;
    init_systick();
    printf("%02d:%02d:%02d\r", seconds / 3600, seconds /60 % 60, seconds % 60);
    while (1){
        if (count == 1000){ //if count == 10 to make it run 10 times faster
            seconds += 1;
            count = 0;
            printf("%02d:%02d$%02d\r", seconds / 3600, seconds /60 % 60, seconds % 60);
        }

    }

}