/*
 * project.c
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#include <stdint.h>
#include <string.h>
#include "printf.h"
#include "UART.h"
#include "LED.h" // Include necessary headers
#include "Systick.h"
#include "song.h"
#include "GPIO.h"
#include "Activity_8.h"
#include "part1.h"
#include "stm32l4xx_hal.h"
#include "getSongInfo.h"

int led_toggle = 0; //used for turning on LED 
int remote_toggle = 0; //0 for local, 1 for remote
int mode = 0; // flag to keep track between remote vs local modes. 0 is local, 1 is remote
int current_song_num = 0;
int button_hold = 0;
int button_count = 0;
int listening = 0;
int button_mode = 0; //1 when pressed, 0 when untouched, 2 for hold
int button_pressed = 0;



/**
 * @brief - handler for the blue button
 */
void EXTI15_10_IRQHandler () {
	EXTI->PR1 |= (1 << 13); // clear the pending bit
	mode = !mode; // toggle between local and remote modes
    printf("\r\n%s\r\n", (mode == 1) ? "***REMOTE MODE ACTIVE***" : "***MANUAL OVERRIDE ACTIVE***");
	LED_Off(LED_PIN); //turn off the led
}

/**
 * @brief - handler for the s1 button
 * 
 */
void EXTI9_5_IRQHandler() {
    EXTI->PR1 |= (1 << 9); // Clear the pending bit
	if (mode == 1){
		GPIO_PinState status = HAL_GPIO_ReadPin(S1_GPIO_Port, S1_Pin);
		if(status == 1) {
            button_mode = 1;
        }
        else if(status == 0) { //button is released
            button_mode = 2;
        }
	}
	
}


/*
* @brief - prints the prompt for the user
*/
void printPrompt() {
    printf("***REMOTE LED CONTROL MENU***\n");
    printf("Available User Commands\n");
    printf("NEXT – Show next song info\n");
    printf("PLAY – Play the song (LED on)\n");
    printf("PAUSE – Pause the song (LED flash)\n");
    printf("STOP – Stop the song (LED off)\n");
    printf("HELP – Show this menu\n");
    printf("QUIT – Exit the program\n");
}

/**
 * @brief - turns on the led
 */
void playSong(){
	LED_On(LED_PIN);
}

/**
 * @brief - displays the next song info
 */
void nextSong(){
	song current_song_array = get_song(current_song_num);
	unsigned char* current_song = current_song_array.p_song;
	int size = current_song_array.size; 
	next_song(current_song, size); //retrieve the next song details
	current_song_num = (current_song_num == 4) ? 0 : current_song_num + 1; //back to first song if at last song else increment
}

/**
 * @brief - turns the led off
 */
void stopSong(){
	LED_Off(LED_PIN);
}

/**
 * @brief - toggles led on and of
 * @param n boolean
 */
void led_toggler(int n){
	if (n == 1){
		LED_On(LED_PIN);
	}
	else{
		LED_Off(LED_PIN);
	}
}


void run_project(){
	printPrompt();
	init_systick(); 
	GPIO_Init();
	char input[128]; // buffer for input
	int buffer_index = 0; // index to keep track of position in buffer
	int count = 0; // count for pause to make sure flashing 1/sec
	int pause = 0; // flag to keep track of whether light should be flashing or not. pseudo-boolean
	char byte; // used to store each character when reading user input

	while(1){
		if(mode == 0){ //MODE = LOCAL
			delay_systick(); // start systick timer
			byte = USART_Read_Nonblocking(USART2); // read in character
			printf("%c", byte);
			if(byte == '\r'){ // once enter is pressed
				input[buffer_index] = '\0'; //add terminating character
				buffer_index = 0; // reset the index to prepare for the next command
				printf("%s\r\n", (char*)input);

				if(strcmp(input, "NEXT") == 0){ // if user entered next
					pause = 0;
					nextSong();
				}
				else if(strcmp(input, "PLAY") == 0){ // turn on led
					pause = 0;
					playSong();
				}
				else if (strcmp(input, "HELP") == 0){ //prints the help menu
					printPrompt();
				}
				else if(strcmp(input, "PAUSE") == 0){ // if user entered pause
					pause = 1;
				}
				else if(strcmp(input, "STOP") == 0) { // turns off led
					pause = 0;
					stopSong();
				}
				else if (strcmp(input, "QUIT") == 0){ //quit the program
					break;
				}
				else{ 
					printf("Invalid Command\r\n");
				}
			}

			else if(byte != 0){ // if not enter, keep adding to buffer
				input[buffer_index] = (char) byte;
				buffer_index++;
			}

			if (pause == 1){ // if pause is set, flash the led
				if(count == 1000){
					LED_Toggle(LED_PIN);
					count = 0;
				}
				count++;
			}
		}

		
		else if(mode == 1){ // remote mode controls. Not allowed to type. 
			delay_systick(); 
			byte = USART_Read_Nonblocking(USART2);

			if (button_mode == 1){
				button_count++;
				// printf("%d\n", button_count);
			}

			if (button_mode == 2 && button_count > 80){ //long pressed
				stopSong();
				button_count = 0;
				listening = 0;
				button_mode = 0;
			}

			if (button_pressed == 0 && button_mode == 2) {
				// Toggle LED and reset button states
				led_toggle = !led_toggle;
				led_toggler(led_toggle);
				button_mode = 0;
				button_pressed = 1;
			} 
			else if (button_pressed == 1 && button_mode == 2 && button_count <= 40) {
				// If button pressed and mode is 2 and button count is within limits
				nextSong(); // Assuming this function plays the next song
				// printf("%d", button_count); // Print button count
				button_pressed = 0;
				button_mode = 0; 
				button_count = 0; // Reset button count
			}
		
		}
	}
}

















