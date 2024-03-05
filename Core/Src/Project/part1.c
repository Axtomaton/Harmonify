/**
 * @file part1.c
 * @author Ivan Lin - il9082@rit.edu
 * @brief - Part 1 of the project.
 * @date 2024-03-05 
 */



#include <stdint.h>
#include <string.h>
#include "printf.h"
#include "UART.h"
#include "LED.h" // Include necessary headers
#include "Systick.h"
#include "song.h"
#include "Activity_8.h"

static int currentTask = -1; //negative one so we start at track 0 when we increment by 1

void printPrompt() {
    printf("***REMOTE LED CONTROL MENU***\n");
    printf("Available User Commands\n");
    printf("NEXT – Show next song info\n");
    printf("PLAY – Play the song (LED on)\n");
    printf("PAUSE – Pause the song (LED flash)\n");
    printf("STOP – Stop the song (LED off)\n");
    printf("HELP – Show this menu\n");
    printf("QUIT – Exit the program\n");
}

/**
 * @brief - Run when the user selects the pause command it will toggle the LED in the background
 */
void LED_ToggleInBackground() {
    init_systick();
    for (int i=0;i<70;i++) {
        delay_systick();
        LED_Toggle(LED_PIN);
    }
}

/**
 * @brief - function uses the song struct fron song.h to get the next song and print the song details
 * like the title, copyright, and tempo
 */
void nextSong() {
    currentTask = (currentTask + 1) % 6; // if it gets to 5, we want to go back to 0
    char songTitle[128] = {};
    char songCopyright[128] = {};
    int titleIndex = 0, copyrightIndex = 0, mtrkCount = 0;
    song currentSong = get_song(currentTask);


    int i = 0;
    while (1) { // Parse for title
        if (currentSong.p_song[i] == 255 && currentSong.p_song[i + 1] == 3) { // Title meta event
            break;
        }
        if (currentSong.p_song[i] == 77 && currentSong.p_song[i + 1] == 84 && currentSong.p_song[i + 2] == 114 && 
            currentSong.p_song[i + 3] == 107) { // MTrk
            mtrkCount++;
        }
        i++;
    }
    // If we don't find the second mtrk that means that the title exists
    if (mtrkCount != 2) { 
        int numToCount = currentSong.p_song[i + 2];
        i++;
        for (int p = i; p <= numToCount + i + 1; p++) {
            songTitle[titleIndex] = (char) (currentSong.p_song[p]);
            titleIndex++;
        }
    }

    i = 0; //reset index to 0
    mtrkCount = 0; //reset mtrk count to 0
    while (1) { // Parse for copyright
        if (currentSong.p_song[i] == 255 && currentSong.p_song[i + 1] == 2) { // Title meta event
            break;
        }
        if (currentSong.p_song[i] == 77 && currentSong.p_song[i + 1] == 84 && currentSong.p_song[i + 2] == 114 &&
            currentSong.p_song[i + 3] == 107) { // MTrk
            mtrkCount++;
        }
        i++;
        if (mtrkCount == 2) { // If we find the second mtrk, break
            break;
        }
    }

    if (mtrkCount != 2) { // If we don't find the second mtrk that means that the title exists
        int numToCount = currentSong.p_song[i + 2];
        i++;
        for (int p = i + 2; p <= numToCount + i + 1; p++) {
            songCopyright[copyrightIndex] = (char) (currentSong.p_song[p]);
            copyrightIndex++;
        }
    }

    i = 0;
    mtrkCount = 0;
    int tempo = 0;
    while (1) { // Parse for tempo
        if (currentSong.p_song[i] == 255 && currentSong.p_song[i + 1] == 81) { // Tempo meta event, we break
            break; 
        } 
        if (currentSong.p_song[i] == 77 && currentSong.p_song[i + 1] == 84 && currentSong.p_song[i + 2] == 114 && 
            currentSong.p_song[i + 3] == 107) { 
            mtrkCount++;
        }
        i++;
        if (mtrkCount == 2) { // If we find the second mtrk, break
            break;
        }
    }
    if (mtrkCount != 2) { //// If we don't find the second mtrk that means that the tempo exists
        tempo = (currentSong.p_song[i + 3] << 16) | (currentSong.p_song[i + 4] << 8) | currentSong.p_song[i + 5]; // Parse tempo
    }

    // Print song details
    printf("Current Song: \n");
    printf("Song Title:%s\n",  songTitle);
    printf("Song Copyright: %s\n",  songCopyright);
    printf("Song Tempo: %d\n", tempo);
}

void processCommands() {
    char* input = readline();

    while (1) {
        // Check user input against available commands
        if (strcmp(input, "STOP") == 0) {
            LED_Off(LED_PIN); // Turn off LED
        } else if (strcmp(input, "PAUSE") == 0) {
            LED_ToggleInBackground(); // Toggle LED in background
        } else if (strcmp(input, "NEXT") == 0) {
            nextSong(); // Get next song
        } else if (strcmp(input, "PLAY") == 0) {
            LED_On(LED_PIN); // Turn on LED
        } else if (strcmp(input, "HELP") == 0) {
            printPrompt(); // Print available commands
        } else if (strcmp(input, "QUIT") == 0) {
            break; // Exit program
        }
        input = readline();
    }
}