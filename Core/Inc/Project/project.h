/*
 * project.h
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */


#ifndef INC_PROJECT_H_
#define INC_PROJECT_H_

void EXTI15_10_IRQHandler();
void EXTI9_5_IRQHandler();
void printPrompt();
void playSong();
void nextSong();
void stopSong();
void led_toggler(int n);
void run_project();

#endif /* PROJECT_H */
