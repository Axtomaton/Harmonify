
#include "hw5.h"
#include "LED.h"
#include "UART.h"
#include "Systick.h"
#include "printf.h"
#include "Activity_8.h"

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