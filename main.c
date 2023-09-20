// This is the driver file for a simulated Tortoise vs Hare race.

#include <stdio.h>
#include <ctype.h>

#include "simulation.h"

int main (void) {

    // Declare Variable
    char playGame;

    // Prompt user to begin a race
    printf("\n\nWould you like to watch a race? (Y/N)\n");
    scanf(" %c", &playGame);

    // Initiate a race and prompt the user to watch another
    while (toupper(playGame) == 'Y') {
        playGame = ' ';

        // Begin race
        runOneGame();

        // Prompt user to race again
        printf("\n\nWould you like to watch another race? (Y/N)\n");
        scanf(" %c", &playGame);
    }

    return 0;
}