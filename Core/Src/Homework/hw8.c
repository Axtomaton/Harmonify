/**
 * @file hw8.c
 * @author Ivan Lin - il9082@rit.edu
 * @date 2024-04-15
 */

#include <stdint.h>
#include "printf.h"
#include "hw8.h"


/**
 * @brief - Parse delay bytes to a uint32_t
 * @param delay - midi message delay bytes
 * @return uint32_t - integer value for the delay
 */
uint32_t parseDelay(uint8_t* delay) {
    int i = 0;
    uint32_t parsed_delay = 0;

    while (delay[i] & 0x80) { 
        parsed_delay = (parsed_delay << 7) | (delay[i] & 0x7F);
        i++;
    }
    parsed_delay = (parsed_delay << 7) | (delay[i] & 0x7F);
    return parsed_delay;
}



/**
 * @brief - Runs the examples from the homeworks
 */
void test_Parsing(){
    uint8_t t1[] = {0x3B, 0x80, 0x27, 0x00};
    uint8_t t2[] = {0x83, 0x18, 0x91, 0x54, 0x64};
    uint8_t t3[] = {0xC5, 0x92, 0x74, 0xE3, 0x74, 0x12};
    uint8_t t4[] = {0x90, 0x82, 0x93, 0x64, 0xD3, 0x89};

    printf("Expected 59, Recieved: %lu\r\n", parseDelay(t1));
    printf("Expected 408, Recieved: %lu\r\n", parseDelay(t2));
    printf("Expected 1132916, Recieved: %lu\r\n", parseDelay(t3));
    printf("Expected 33589732, Recieved: %lu\r\n", parseDelay(t4));
}