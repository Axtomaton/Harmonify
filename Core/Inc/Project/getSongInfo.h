#ifndef GET_SONG_INFO_H
#define GET_SONG_INFO_H

void getTitle(unsigned char* current_song, int song_size);
void getCopyright(unsigned char* current_song, int song_size);
void getTempo(unsigned char* current_song, int song_size);
void next_song(unsigned char* current_song, int song_size);

#endif /* GET_SONG_INFO_H */