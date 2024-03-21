
/**
 * @file Activity_10.c
 * @author Ivan LIn
 * @date 2024-03-21 
 */


#include "stm32l4xx.h" // Board Constants
#include "printf.h"
#include "GPIO.h"
#include "main.h" // B1 constants


/** 
The blue button is wired in such a way that it is always on except when it is pressed. Thus all the logic is reversed from the black button.
*/
void blue_button_check () {
    GPIO_Init ();
    while (1) {
      // Print message when the blue button is pressed
      if (!(B1_GPIO_Port->IDR & B1_Pin)) {
              printf ("Blue button pressed\n");
      }
    }
}
 