/**
 * @file wave.c
 * @author Ivan Lin - il9082@rit.edu
 * @date 2024-04-11
 */

#include "printf.h"
#include "Systick.h"
#include "Activity_11.h"
#include "tone.h"
#include "stdint.h"

void wave(float frequency){
    uint32_t duration = hertz_to_midi_ticks(frequency);
    DAC_Init();
    DAC_Start ();    
    int count = get_time() % duration;
    DAC_Set_Value (2048);
    if (count < duration >> 1){ //divide by 2, takes 1 clock cycle.
        printf("1");
    }
    else{
        printf("0");
    }
    // printf("%d\n", duration); 

    //print 1's for half the frequency
    //print 0's for other half. 
}

void run_wave(){
    init_systick();
    float frequency = 0.5;
    while (1){
        wave (frequency);
    }
}