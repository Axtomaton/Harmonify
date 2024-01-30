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

char buffer[256]; //buffer to store formatted string

int do_printf(const char* format, ...){
	va_list aptr; //traverse arguments
	int ret; //return value of vsprintf
	va_start (aptr, format);
	ret = vsprintf(buffer, format, aptr); //formats the string
	va_end (aptr);
	USART_Write(USART2, (unsigned char*)buffer, ret); //writes it to minicom
	return (ret); //number of chars written to the buffer.
}


