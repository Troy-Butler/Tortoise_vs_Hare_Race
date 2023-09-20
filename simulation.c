// This is the implementation file for the simulation.h header file.

// This file contains function definitions for controlling character
// movements in a simulated Tortoise vs Hare race.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "simulation.h"

// This function handles movements of the Tortoise
void moveTortoise (unsigned int *ptrTurtle) {
    // Generate random number between 0 and 99
    unsigned int turtleMove = rand() % 100;
    if (turtleMove < 50) { // Fast Pace - move 3 spaces forward
        *ptrTurtle += 3; 
    }
    else if (turtleMove < 75) { // Slip - move 6 spaces backward
        if (*ptrTurtle < 6) {
            *ptrTurtle = 0; // set position to 0 if within 6 spaces of start
        }
        else {
            *ptrTurtle -= 6; // otherwise move tortoise back 6 spaces
        }
    }
    else {
        *ptrTurtle += 1; // Slow Pace - move 1 space forward
    }
}

// This function handles movements of the Hare
void moveHare (unsigned int *ptrHare) {
    unsigned int hareMove = rand() % 100;
    if (hareMove < 25) { // Sleep - remain in current position
        *ptrHare += 0;
    }
    else if (hareMove < 45) { // Big Hop - move 9 spaces forward
        *ptrHare += 9;
    }
    else if (hareMove < 50) { // Big Slip - move 12 spaces backward
        if (*ptrHare < 12) {
            *ptrHare = 0; // set position to 0 if within 12 spaces of start
        }
        else {
            *ptrHare -= 12; // otherwise move hare back 12 spaces
        }
    }
    else if (hareMove < 80) { // Small Hop - move 1 space forward
        *ptrHare += 1;
    }
    else {
        if (*ptrHare < 2) { // Small Slip - move 2 spaces backward
            *ptrHare = 0; // set position to 0 if within 2 spaces of start
        }
        else {
            *ptrHare -= 2; // otherwise move hare back 2 spaces
        }
    }
}

// This function sets the starting positions and characters for the racers
void setStartValues (Racer *r, int pos, char sym[]) {
    r->position = pos;
    strcpy(r->symbol, sym);
}

// This function runs a single instance of the race.
void runOneGame() {
    // 1000000 microseconds in one second, i.e. usleep(1000000);
    // Generate Race Participants
    srand((int)time(0));
    char raceTrack[100];
    bool winner = false;
    unsigned int trackLength = 70;
    Racer hare;
    Racer tortoise;

    // Initialize Racer Values
    setStartValues(&hare, 0, "H");
    setStartValues(&tortoise, 0, "T");

    // Print Introduction
    printf("\n\n*** Welcome to the Great Tortoise vs Hare Race of 2022!!! ***\n\n");
    usleep(1000000);
    printf("The race will start in: \n");
    for (int i = 3; i > 0; --i) {
        usleep(1000000);
        printf("%d...\n", i);
    }
    usleep(1000000);
    printf("\n...And they're off!\n\n");
    
    // Draw Empty Track
    strcpy(raceTrack, "-");
    while (strlen(raceTrack) < trackLength) {
        strcat(raceTrack, "-");
    }
    printf("%s\n", raceTrack);

    // Begin Race
    while (winner == false) {
        moveHare(&hare.position);
        moveTortoise(&tortoise.position);
        // Build Track and Show Positions
        // Tortoise in the lead
        if (hare.position < tortoise.position) {
            if (hare.position == 0) {
                strcpy(raceTrack, "H");
                if (tortoise.position > trackLength) {
                    while (strlen(raceTrack) < trackLength) {
                        strcat(raceTrack, "-");
                    }
                    while (strlen(raceTrack) < tortoise.position) {
                        strcat(raceTrack, " ");
                    }
                    strcat(raceTrack, "T");
                }
                else {
                    while (strlen(raceTrack) < tortoise.position) {
                        strcat(raceTrack, "-");
                    }
                    strcat(raceTrack, "T");
                    while (strlen(raceTrack) < trackLength) {
                        strcat(raceTrack, "-");
                    }
                }
            }
            else {
                strcpy(raceTrack, "-");
                if (hare.position > trackLength) {
                    while (strlen(raceTrack) < trackLength) {
                        strcat(raceTrack, "-");
                    }
                    while (strlen(raceTrack) < hare.position) {
                        strcat(raceTrack, " ");
                    }
                    strcat(raceTrack, "H");
                    while (strlen(raceTrack) < tortoise.position) {
                        strcat(raceTrack, " ");
                    }
                    strcat(raceTrack, "T");
                }
                else if (tortoise.position > trackLength) {
                    while (strlen(raceTrack) < hare.position) {
                        strcat(raceTrack, "-");
                    }
                    strcat(raceTrack, "H");
                    while (strlen(raceTrack) < trackLength) {
                        strcat(raceTrack, "-");
                    }
                    while (strlen(raceTrack) < tortoise.position) {
                        strcat(raceTrack, " ");
                    }
                    strcat(raceTrack, "T");
                }
                else {
                    while (strlen(raceTrack) < hare.position) {
                        strcat(raceTrack, "-");
                    }
                    strcat(raceTrack, "H");
                    while (strlen(raceTrack) < tortoise.position) {
                        strcat(raceTrack, "-");
                    }
                    strcat(raceTrack, "T");
                    while (strlen(raceTrack) < trackLength) {
                        strcat(raceTrack, "-");
                    }
                }
            }
        }
        else if (hare.position > tortoise.position) {
            // Hare in the lead
            if (tortoise.position == 0) {
                strcpy(raceTrack, "T");
                if (hare.position > trackLength) {
                    while (strlen(raceTrack) < trackLength) {
                        strcat(raceTrack, "-");
                    }
                    while (strlen(raceTrack) < hare.position) {
                        strcat(raceTrack, " ");
                    }
                    strcat(raceTrack, "H");
                }
                else {
                    while (strlen(raceTrack) < hare.position) {
                        strcat(raceTrack, "-");
                    }
                    strcat(raceTrack, "H");
                    while (strlen(raceTrack) < trackLength) {
                        strcat(raceTrack, "-");
                    }
                }
            }
            else {
                strcpy(raceTrack, "-");
                if (tortoise.position > trackLength) {
                    while (strlen(raceTrack) < trackLength) {
                        strcat(raceTrack, "-");
                    }
                    while (strlen(raceTrack) < tortoise.position) {
                        strcat(raceTrack, " ");
                    }
                    strcat(raceTrack, "T");
                    while (strlen(raceTrack) < hare.position) {
                        strcat(raceTrack, " ");
                    }
                    strcat(raceTrack, "H");
                }
                else if (hare.position > trackLength) {
                    while (strlen(raceTrack) < tortoise.position) {
                        strcat(raceTrack, "-");
                    }
                    strcat(raceTrack, "T");
                    while (strlen(raceTrack) < trackLength) {
                        strcat(raceTrack, "-");
                    }
                    while (strlen(raceTrack) < hare.position) {
                        strcat(raceTrack, " ");
                    }
                    strcat(raceTrack, "H");
                }
                else {
                    while (strlen(raceTrack) < tortoise.position) {
                        strcat(raceTrack, "-");
                    }
                    strcat(raceTrack, "T");
                    while (strlen(raceTrack) < hare.position) {
                        strcat(raceTrack, "-");
                    }
                    strcat(raceTrack, "H");
                    while (strlen(raceTrack) < trackLength) {
                        strcat(raceTrack, "-");
                    }
                }
            }
        }
        else {
            // Hare and Tortoise in same position
            if (hare.position == 0) {
                strcpy(raceTrack, "OUCH!"); // tortoise bite hare
                while (strlen(raceTrack) < trackLength) {
                    strcat(raceTrack, "-");
                }
            }
            else if (hare.position > trackLength) {
                strcpy(raceTrack, "-");
                while (strlen(raceTrack) < trackLength) {
                    strcat(raceTrack, "-");
                }
                while (strlen(raceTrack) < hare.position) {
                    strcat(raceTrack, " ");
                }
                strcat(raceTrack, "OUCH!"); // tortoise bite hare
            }
            else {
                strcpy(raceTrack, "-");
                while (strlen(raceTrack) < hare.position) {
                    strcat(raceTrack, "-");
                }
                strcat(raceTrack, "OUCH!");
                while (strlen(raceTrack) < trackLength) {
                    strcat(raceTrack, "-");
                }
            }
        }

        usleep(1000000);
        printf("%s\n", raceTrack);

        // Check for winner
        // Both racers have crossed finish line
        if (hare.position >= trackLength && tortoise.position >= trackLength) {
            winner = true;
            printf("WOW!!! A TIE!!!\n");
        }
        // Hare has crossed finish line alone
        else if (hare.position >= trackLength) {
            winner = true;
            printf("HARE WINS!!!\n");
        }
        // Tortoise has crossed finish line alone
        else if (tortoise.position >= trackLength) {
            printf("TORTOISE WINS!!!\n");
            winner = true;
        }
        // Otherwise race has not yet been won
        else {
            winner = false;
        }
    }
}