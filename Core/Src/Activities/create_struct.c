/*
 * create_struct.c
 *
 *  Created on: Feb 1, 2024
 *      Author: ivanl
 */



//create a struct for the MIDI header

struct MIDI_Header{
	char ChunkType [4];
	unsigned int headerLength; //32 bit length
	unsigned short format; //16 bits
	unsigned short ntrks; //16 bits
	unsigned short division; //bits

};
