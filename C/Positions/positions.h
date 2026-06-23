#ifndef POSITIONS_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


typedef enum {
    CREATE_NEW = 1,
    DESTROY,
    TRACK,
    DISTANCE,
    EXIT
} CHOICES;

typedef struct {
    int identifier;
    int posX;
    int posY;
    double distanceFromOrigin;
} Object;

Object createNew();
Object objects[10];
int objectCount = 0;

int menu(int programState);
void trackPositions();
void calculateDistance(int identity);
void removeObject();


#endif