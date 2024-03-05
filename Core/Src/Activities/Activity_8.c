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
    uint8_t byte = USART_Read(USART2); 
    putchar (byte);
    if (byte == '\r'){
        putchar('\n');
    }
    return byte;
}

char* readline() {
    char byte;
    int i = 0;

    while (1) {
        byte = read_and_echo_byte();
        if (byte == '\r') {
            break;  // Exit the loop when newline is encountered
        }
        BUFFER[i++] = byte;
        if (i >= sizeof(BUFFER) - 1) {
            // Buffer overflow protection
            BUFFER[i] = '\0';
            return BUFFER;
        }
    }
    BUFFER[i] = '\0';

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