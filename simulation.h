#ifndef SIMULATION_H
#define SIMULATION_H

typedef struct Racer_struct {
    unsigned int position;
    char symbol[2];
} Racer;

void moveTortoise (unsigned int *ptrTurtle);
void moveHare (unsigned int *ptrHare);
void setStartValues (Racer *r, int pos, char sym[]);
void runOneGame();

#endif