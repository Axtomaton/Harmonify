/**
 * @file hw5.c
 * @author Ivan Lin -il9082@rit.edu
 * @brief File for homework 5
 * @date 2024-02-27
 */


#include "hw5.h"
#include "LED.h"
#include "UART.h"
#include "Systick.h"
#include "printf.h"
#include "Activity_8.h"

/**
 * @brief This function runs the test for the LED and UART. 
 * It toggles the LED and echos the user input through USART_Read_Nonblocking
 */
void test_LED(){
    init_systick(); // Initialize the systick

    int count = 0;
    while(1){

        uint8_t byte = USART_Read_Nonblocking(USART2); // read character and echo

        if (byte != 0){ // make sure valid character
            putchar (byte);// echo output
        }
        // delay
        delay_systick(); 
        count ++;
        if (count == 10){
            LED_Toggle(LED_PIN); // toggle led
            count = 0;
        }
    }
}