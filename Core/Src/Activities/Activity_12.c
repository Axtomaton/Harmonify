/**
 * @file Activity_12.c
 * @author Ivan Lin - il9082@rit.edu 
 * @date 2024-03-26 
 */


#include <stm32l476xx.h>
#include "GPIO.h"
//same thing with activity 10 but with interrupts

void setup (){
    GPIO_Init();
    NVIDC_EnableIRQ (EXTI15_10_IRQn);
}

void EXTI_15_10_IRQHandler (){

    printf ("Blue Button Pressed!\n");
    HAL_GPIO_EXTI_IRQHandler(B1_Pin);  
    // NVIC_ClearPendingIRQ(EXTI15_10_IRQn);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    switch (GPIO_Pin){
        case B1_Pin:
            printf("Blue Button Pressed!\n");
            break;
        }
}