#include <stdio.h>
#include <ctype.h>

#include "simulation.h"

int main (void) {

    char playGame;

    printf("\n\nWould you like to watch a race? (Y/N)\n");
    scanf(" %c", &playGame);

    while (toupper(playGame) == 'Y') {
        playGame = ' ';
        runOneGame();
        printf("\n\nWould you like to watch another race? (Y/N)\n");
        scanf(" %c", &playGame);
    }

    return 0;
}