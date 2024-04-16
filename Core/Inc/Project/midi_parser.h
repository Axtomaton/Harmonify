/**
 * @file midiparse.h
 * @author Ivan Lin - il9082@rit.edu
 * @date 2024-03-28
 */

#ifndef MIDI_PARSER_H
#define MIDI_PARSER_H

void parseTitle(unsigned char* song, int size);
void parseTempo(unsigned char* song, int size);
void parseCopyright(unsigned char* song, int size);
void parseMIDI(unsigned char* song, int size);


#endif