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
    init_systick(); // Initialize SysTick for delay
    while(1) {
        LED_Toggle(LED_PIN); // Toggle LED pin
        char ch = read_and_echo_byte(); //check for user input
        if(ch != 0) { //if there is a character
            printf("%c\n", ch); // Echo received character
        }
        delay_systick(); //delays the next iteration once per scond. Makes input super slow. 
    }
}