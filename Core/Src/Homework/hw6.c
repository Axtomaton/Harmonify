/*
@author: Ivan Lin -il9082@rit.edu
@date: 2024-03-27
@brief: Homework 6
*/

#include <stdint.h>
#include <stm32l476xx.h>
#include "UART.h"



//Need to have interrupts enablkaded at NVIC, using NVIC_EnableIRQ (EXTI4_IRQn)

/**
 * @brief - This function enables USART2 read interruprs at the NVIC level. Only enable the interrupr for 
 * RXNE
 */
void USART2_IRQHandler(void){
    //Check if the interrupt is for RXNE
    if(USART2->ISR & (1 << 5)){
        uint8_t data = USART2->RDR;
        USART_Write(USART2, &data, 1);
    }

}
