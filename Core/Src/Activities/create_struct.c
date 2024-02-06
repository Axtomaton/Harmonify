/*
 * create_struct.c
 *
 *  Created on: Feb 1, 2024
 *      Author: ivanl
 */

#include "song.h"
#include "printf.h"

//create a struct for the MIDI header

struct MIDI_Header{
	char ChunkType [4];
	unsigned int headerLength; //32 bit length
	unsigned short format; //16 bits
	unsigned short ntrks; //16 bits
	unsigned short division; //bits

};

void user_header(){
	unsigned char* song = get_song (0).p_song;
	struct header* song_header = song; //casting the song to a header. Reinterpreting the information a diff way.

	//print out all the pieces of the header, one per line.

	vsprintf("ChunkType: %s\n", song_header->ChunkType);
	


	
}