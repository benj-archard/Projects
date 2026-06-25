#ifndef VEHICLES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    CREATE = 1,
    SHOW_ALL,
    SHOW_ONE,
    MOVE,
    RENAME,
    EXIT
} MENU;


typedef struct {
    int id;

    char name[50];

    int posX;
    int posY;

} Vehicle;

Vehicle createVehicle(int *vCount);
Vehicle* findVehicle(Vehicle vArray[], int *vCount, int id);

int menu(Vehicle vArray[], int* vCount);
void showVehicles(Vehicle vArray[], int *vCount);
void showOneVehicle(Vehicle vArray[], int* vCount);
void moveVehicle(Vehicle vArray[], int *vCount);
void renameVehicle(Vehicle vArray[], int *vCount);


#endif