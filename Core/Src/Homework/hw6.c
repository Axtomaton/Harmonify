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
    if(USART2->ISR & USART_ISR_RXNE){
        uint8_t data = USART_Read(USART2);
        printf("%c", data);
        // USART_Write(USART2, &data, 1);
    }

}
