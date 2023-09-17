#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#include "simulation.h"

void moveTortoise (unsigned int *ptrTurtle) {
    unsigned int turtleMove = rand() % 100;
    if (turtleMove < 50) {
        *ptrTurtle += 3; // Fast Pace
    }
    else if (turtleMove < 75) {
        if (*ptrTurtle < 6) {
            *ptrTurtle = 0; // Slip
        }
        else {
            *ptrTurtle -= 6; // Slip
        }
    }
    else {
        *ptrTurtle += 1; // Slow Pace
    }
}

void moveHare (unsigned int *ptrHare) {
    unsigned int hareMove = rand() % 100;
    if (hareMove < 25) {
        *ptrHare += 0; // Sleep
    }
    else if (hareMove < 45) {
        *ptrHare += 9; // Big Hop
    }
    else if (hareMove < 50) {
        if (*ptrHare < 12) {
            *ptrHare = 0; // Big Slip
        }
        else {
            *ptrHare -= 12; // Big Slip
        }
    }
    else if (hareMove < 80) {
        *ptrHare += 1; // Small Hop
    }
    else {
        if (*ptrHare < 2) {
            *ptrHare = 0; // Small Slip
        }
        else {
            *ptrHare -= 2; // Small Slip
        }
    }
}

void setStartValues (Racer *r, int pos, char sym[]) {
    r->position = pos;
    strcpy(r->symbol, sym);
}

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

    // Race!!!
    while (winner == false) {
        moveHare(&hare.position);
        moveTortoise(&tortoise.position);
        // Build Track and Show Positions
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
            // Reverse of above
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
            if (hare.position == 0) {
                strcpy(raceTrack, "OUCH!");
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
                strcat(raceTrack, "OUCH!");
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
        if (hare.position >= trackLength && tortoise.position >= trackLength) {
            winner = true;
            printf("WOW!!! A TIE!!!\n");
        }
        else if (hare.position >= trackLength) {
            winner = true;
            printf("HARE WINS!!!\n");
        }
        else if (tortoise.position >= trackLength) {
            printf("TORTOISE WINS!!!\n");
            winner = true;
        }
        else {
            winner = false;
        }
    }
}