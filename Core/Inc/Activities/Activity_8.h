/**
 * @file Activity_8.h
 * @author Ivan Lin - il9082@rit.edu
 * @brief Header file for Activity 8
 * @date 2024-02-20
 */

#ifndef ACTIVITY_8_H_
#define ACTIVITY_8_H_

#include <stdint.h>

/**
 * @brief Function to read a byte from USART2 and echo it back
 * 
 * @return char The byte read
 */
char read_and_echo_byte();

/**
 * @brief Function to read a line from USART2
 * 
 * @return char* Pointer to the buffer containing the line read
 */
char* readline();

/**
 * @brief Function to continuously read lines from USART2 and print them
 */
void readlines();

/**
 * @brief Function to continuously read bytes from USART2 and echo them back
 */
void read_bytes();

#endif /* ACTIVITY_8_H_ */
