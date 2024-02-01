/*
 * printf.c
 *
 *  Created on: Jan 29, 2024
 *      Author: ivanl
 */

#include "printf.h"
#include "UART.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

static char buffer[256]; //buffer to store formatted string. now it's private to this file only.

int do_printf(const char* format, ...){
	va_list aptr; //traverse arguments
	int ret; //return value of vsprintf
	va_start (aptr, format);
	ret = vsprintf(buffer, format, aptr); //formats the string
	va_end (aptr);
	USART_Write(USART2, (unsigned char*)buffer, ret); //writes it to minicom
	return (ret); //number of chars written to the buffer.
}

int puts(const char* str){
	int ret = sprintf(buffer, "%s\r\n");
	USART_Write(USART2, (unsigned char*) buffer, ret);
	return ret;
}

int putchar(char c){
	USART_Write(USART2, (unsigned char*) &c, 1);
	return c;
}


int printf(const char* format, ...){
	va_list aptr;
	int ret;
	va_start(aptr, format);
	ret = vsprintf(buffer, format, aptr);


}



//
//char* example(){ //don't do this, don't return a pointer because it will be overwritten. Either pass in ptr or make it static, or apart of fiel.
//	char buffer[20] = "Hello World!";
//	return buffer;
//}

