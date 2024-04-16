

#include "GPIO.h"
#include "DAC.h"
#include "dac.h"
#include "printf.h"


void make_nose(){
    GPIO_Init();
    //Turn on DAC witha  power of 2048. 
    DAC_Init();
    DAC_Start ();
    //reference adc_Dac_demo
    
    while (1){
        DAC_Set_Value (4000);
        printf(1);
    }
    //positive goses to A2 on your board
}