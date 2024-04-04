#include "printf.h"
#include "UART.h"

#include <stdio.h>
#include <stdarg.h>

static char buffer[128];

int puts (const char* str) {
    int ret = sprintf (buffer, "%s\r\n", str);
    USART_Write (USART2, (unsigned char*) buffer, ret);
    return ret;
}

int putns (const char* str, int n) {
	int ret = sprintf (buffer, "%d%s\r\n", n, str);
	USART_Write (USART2, (unsigned char*) buffer, ret);
	USART_Write (USART2, (unsigned char*) "\r\n", 2);
	return ret;
}


int putchar (int c) {
    USART_Write (USART2, (unsigned char*) &c, 1);
    return c;
}

int printf (const char *format, ...) {
   va_list aptr;
   int ret;

   va_start(aptr, format);
   ret = vsprintf(buffer, format, aptr);
   va_end(aptr);
   if (buffer [ret - 1] == '\n') {
       buffer [ret - 1] = '\r';
       buffer [ret] = '\n';
       buffer [ret + 1] = 0;
       ret++;
   }

   USART_Write (USART2, (unsigned char*) buffer, ret);

   return(ret);
}

