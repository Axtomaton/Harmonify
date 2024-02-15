/*
 * project.c
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#include "project.h"
#include "printf.h"
#include "bigToLittleEndian.h"


void run_project() {

    uint32_t big_endian_value = 0x01234567; // Big endian value: 0x01234567
	printf("Converting 0x01234567 to little endian\n");

    // Convert big-endian value to little-endian uint16_t and uint32_t
    uint16_t little_endian_uint16 = convert_to_uint16((uint8_t*)&big_endian_value);
    uint32_t little_endian_uint32 = convert_to_uint32((uint8_t*)&big_endian_value);

    printf("Converted value in little endian (uint16_t): %04x\n", little_endian_uint16);
    printf("Converted value in little endian (uint32_t): %08x\n", little_endian_uint32);
	display_song_info();
}

//	puts("hello world");
	// char* str = "Hello, World!";
	// printf("%s", str);
//	do_printf("%s,\n", char* hello_world);



// use_header();

/**
 * big endian is msb to lsb, little endian is lsb to msb. 
 * 1010 0101 1100 1010 <big endian>
 * 0101 1100 1010  0101 <little endian>.
 * Bitwise Boolean Operators: &, |, ^
 * Shifting: left = add 0. right - remove left element
 * Inversion: ~, inverts all the bits. 
 */

