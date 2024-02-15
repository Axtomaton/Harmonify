#include <stdio.h>
#include <stdint.h>
#include "bigToLittleEndian.h"
#include "song.h"


/**
 * 
 * @author Ivan Lin - il9082@rit.edu
 * @date 2024-02-14
 * @brief Homework 4 - code solution
 */


struct midi{
    char chunkType[4]; // 4 ASCII characters
    unsigned int length; // 32 bits
    unsigned short format; // 16 bits
    unsigned short ntrcks; // 16 bits
    unsigned short division; // 16 bits
};

/**
 * @brief converts the big endian value to 16 bit little endian
 * @param p_value 
 * @return uint16_t 
 */
uint16_t convert_to_uint16 (uint8_t* p_value){
    return (p_value[0] << 8) | p_value[1]; //shift the first byte 8 bits tot he left and then or it with the second byte.
}

/**
 * @brief converts the big endian value to 32 bit little endian
 * @param p_value 
 * @return uint32_t 
 */
uint32_t convert_to_uint32 (uint8_t* p_value){
    //shift the first byte 24 bits to the left, then or it with the second byte shifted 16 bits to the left, then or it with the third byte shifted 8 bits to the left, then or it with the fourth byte
    return (p_value[0] << 24) | (p_value[1] << 16) | (p_value[2] << 8) | p_value[3]; 
}

/**
 * @brief displays the song info from activity 9
 */
void display_song_info(){
    //copied over from activity 9
    unsigned char* song = get_song(0).p_song;
    struct midi* song_header = (struct midi*)song;
    puts(song_header->chunkType);
    printf("Length: %ld\n", convert_to_uint32((uint8_t*)&song_header->length)); //32 bit
    printf("Format: %d\n", convert_to_uint16((uint8_t*)&song_header->format)); //16 bit
    printf("Number of tracks: %d\n", convert_to_uint16((uint8_t*)&song_header->ntrcks)); //16 bit
    printf("Division: %d\n", convert_to_uint16((uint8_t*)&song_header->division)); //16 bit
}
