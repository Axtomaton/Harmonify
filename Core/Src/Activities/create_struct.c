/*
 * create_struct.c
 *
 *  Created on: Feb 1, 2024
 *      Author: ivanl
 */

#include "song.h"
#include "printf.h"


#include <stdint.h>
struct header{
    char chunkType[4]; // 4 ASCII characters
    // unsigned takes less space
    unsigned int length; // 32 bits
    unsigned short format; // 16 bits
    unsigned short ntrcks; // 16 bits
    unsigned short division; // 16 bits
};

void use_header () {
    unsigned char* song = get_song (0).p_song;
    struct header* song_header = (struct header*)song;

    // print out all the pieces of the header, one per line
    // putns (song_header->chunkType, 4);
    printf ("%d\n", song_header->length);
    printf ("%d\n", song_header->format);
    printf ("%d\n", song_header->ntrcks);
    printf ("%d\n", song_header->division);
}