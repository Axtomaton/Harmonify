/**
 * @file Activity_8.c
 * @author Ivan Lin - il9082@rit.edu
 * @brief 
 * @date 2024-02-20
 */

#include <stdint.h>
#include "printf.h"
#include "UART.h"

static char BUFFER [80];

char read_and_echo_byte(){
    uint8_t byte = USART_Read_Nonblocking(USART2); 
    putchar (byte);
    if (byte == '\r'){
        putchar('\n');
    }
    return byte;
}

char* readline(){
    //user the Buffer to read one line of user input
    char byte = ' ';
    int i=0;
    for (int i=0; (byte != '\r') && (i < sizeof(BUFFER) -1);i++){
        byte = read_and_echo_byte();
        BUFFER [i] = byte;
    }
    BUFFER[i-1] = 0;
    return BUFFER;
}

char readlines() {
    while (1){
        printf("%s\n", readline());
    }

}

void read_bytes(){
    while (1){
        read_and_echo_byte();
    }
}