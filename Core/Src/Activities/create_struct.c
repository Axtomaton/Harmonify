/*
 * create_struct.c
 *
 *  Created on: Feb 1, 2024
 *      Author: ivanl
 */

#include "song.h"
#include "printf.h"

/**
Creating a struct for the MIDI header
*/

#include "song.h"
#include "printf.h"


struct midi_header{
    char chunkType[4]; // 4 ASCII characters
    // unsigned takes less space
    unsigned int length; // 32 bits
    unsigned short format; // 16 bits
    unsigned short ntrcks; // 16 bits
    unsigned short division; // 16 bits
};

void use_header(){
//    struct header mheader;
//    mheader.division = 256;

    unsigned char* song = get_song(0).p_song;
    struct midi_header* song_header = (struct midi_header*)song;
    // print out all the pieces of the header, one per line
	putns (song_header->chunkType, 4);
    printf("%s\n", song_header->chunkType);
    printf("%d\n", song_header->length);
    printf("%d\n", song_header->format);
    printf("%d\n", song_header->ntrcks);
    printf("%d\n", song_header->division);

}