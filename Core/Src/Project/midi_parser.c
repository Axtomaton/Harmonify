/**
 * @file midi_parser.c
 * @author Ivan Lin - il9082@rit.edu
 * @date 2024-03-28
 */

#include "midi_parser.h"
#include "printf.h"
static int song_tempo = 0;


void parseTitle(unsigned char* song, int size){
    for(int i = 0; i < size; i++){
        if (song[i] == 0xFF && song[i+1] == 0x03){
            int index = 0;
            int length = song[i+2];
            printf("Song Title: ");
            while(index < length){
                printf("%c", song[i+3]);
                i++;
                index++;
            }
            break;
        }
    }
}

void parseTempo(unsigned char* song, int size){
    for (int i = 0; i < size; i++){
        if (song[i] == 0xFF && song[i+1] == 0x51){ 
            printf("Tempo: ");
            int temp = ((song[i + 3]<<16) | (song[i+4]<<8) | (song[i+5]));
            song_tempo = temp; 
            printf("%d\r\n",  temp);
            break;
        }
}
void parseCopyright(unsigned char* song, int size){
    for(int i = 0; i < size; i++){
        if (current_song[i] == 0xFF && current_song[i+1] == 0x02){ /
            int index = 0;
            int length = current_song[i+2];
            printf("Copyright: ");
            while(index < length){
                printf("%c", current_song[i+3]);
                i++, 
                index++;
            }
            break;
        }
    }
}

/**
 * @brief - Function that calls the method above to parse the song file. 
 * @param song 
 * @param size 
 */
void parseMIDI(unsigned char* song, int size){ 
    parseTitle(song, size);
    parseCopyright(song, size);
    parseTempo(song, size);
}


void 

