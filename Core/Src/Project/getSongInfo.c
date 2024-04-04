/**
 * @file getSongInfo.c
 * @author: Ivan Lin
 */

#include "printf.h"
#include "getSongInfo.h"


/**
 * parses song the title of the current song
 * @param current_song - referene to the song currently being parsed.
 * @param song_size - length of the current song array.
 */
void getTitle (unsigned char* current_song, int song_size) {
	// gets title bytes
    for (int i = 0; i < song_size; i++){

        if (current_song[i] == 0xFF && current_song[i+1] == 0x03){
            int index = 0;
            int length = current_song[i+2];
            printf("Song Title: ");
            while(index < length){
                printf("%c", current_song[i+3]);
                i++, index++;
            }
            break;
        }
    }
    printf("\r\n");
}

/**
 * parses the copyright of the current song
 * @param current_song- referene to the song currently being parsed
 * @param song_size- length of the current song array
 */
void getCopyright (unsigned char* current_song, int song_size) {
	// iterates until we see the FF 02 byte
    for (int i = 0; i < song_size; i++){
        if (current_song[i] == 0xFF && current_song[i+1] == 0x02){
            int index = 0;
            int length = current_song[i+2];
            printf("Copyright: ");
            while(index < length){
	            printf("%c", current_song[i+3]);
	            i++, index++;
	        }
            break;
        }
    }
    printf("\r\n"); //formatting
}

/**
 * parses the tempo of the current song. 
 * @param current_song- referene to the song currently being parsed
 * @param song_song_size- length of the current song array
 */
void getTempo(unsigned char* current_song, int song_size) {
    for (int i = 0; i < song_size; i++){
        if (current_song[i] == 0xFF && current_song[i+1] == 0x51){
            printf("Tempo: ");
            int temp = ((current_song[i + 3]<<16) | (current_song[i+4]<<8) | (current_song[i+5]));
            printf("%d\r\n",  temp);
            break;
        }
    }
}

/**
 * Parses song.c for details related to the next song avaliable. Retrieves the song title, copyright, and tempo.
* @param current_song- referene to the song currently being parsed
* @param song_song_size- length of the current song array
 */
void next_song(unsigned char* current_song, int song_size){
    getTitle(current_song, song_size);
    getCopyright(current_song, song_size);
    getTempo(current_song, song_size);
}