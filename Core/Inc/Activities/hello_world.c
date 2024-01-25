/**
 * hello_world.c
 *
 *
 */

#include <stdio.h>
#include "UART.h"



void hello(){
	//use UART to print something.
	char* welcome = "hello, world!\n";
	USART_Write (USART2, (unsigned char *) welcome, 15);

	printf("Enter your name: ");
	char name [64];
	scanf (name);
	printf("Hello, %s\n", name);

}
