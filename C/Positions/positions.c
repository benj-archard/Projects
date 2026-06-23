#include "positions.h"

int menu(int running) {
    int choice = 0;
    printf("\n1) Create new object\n");
    printf("2) Remove an object\n");
    printf("3) Track an object\n");
    printf("4) Calculate distance of object\n");
    printf("5) Exit\n");
    printf("CHOICE => "); scanf("%d", &choice);

    while (choice != CREATE_NEW && choice != DESTROY && choice != TRACK && choice != DISTANCE && choice != EXIT) {
        printf("Invalid input!, please select an options using 1,2,3 or 4\n");
        printf("CHOICE => "); scanf("%d", &choice);
    }

    if (choice == CREATE_NEW) {
        if (objectCount != 10) { 
            objects[objectCount] = createNew();
        }
    } else if (choice == DESTROY) {
        if (objectCount > 0) {
            removeObject();
        }
    } 
    else if (choice == TRACK) {
        trackPositions();
    } else if (choice == DISTANCE) {
        int toCalculate = 0;

        for (int i = 0; i < objectCount; i++) {
            printf("Object #%d\n", objects[i].identifier);
        }

        printf("Please enter the identifier of the object you wish to calculate the distance of: "); scanf("%d", &toCalculate);

        calculateDistance(toCalculate);

        printf("Distance from origin => %f\n", objects[toCalculate].distanceFromOrigin);
    } else if (choice == EXIT) {
        return 0;
    }
    return 1;
}


Object createNew() {
    Object temp;
    objectCount++;

    temp.identifier = objectCount - 1;
    temp.posX = rand() % 1000;
    temp.posY = rand() % 1000;

    return temp;
}

void removeObject() {
    int toRemove = 0;

    for (int i = 0; i < objectCount; i++) {
        printf("Object #%d\n", objects[i].identifier);
    }

    printf("Please enter the identifier of the object you wish to remove: "); scanf("%d", &toRemove);

    for (int i = toRemove; i < objectCount; i++) {
            objects[i] = objects[i+1];
    }

    for (int i = 0; i < objectCount; i++) {
        objects[i].identifier = i;
    }

    objectCount--;
}

void trackPositions() {
    for (int i = 0; i < objectCount; i++) {
            printf("Object #%d\n", objects[i].identifier);
            printf("X: %d\n", objects[i].posX);
            printf("Y: %d\n", objects[i].posY);
    }
}

void calculateDistance(int identity) {
    // Origin is (0,0);
    objects[identity].distanceFromOrigin = 
    sqrt(
        (pow(objects[identity].posX, 2)) + 
        (pow(objects[identity].posY, 2))
    );
}

int main(void) {
    srand(time(0));
    int running = 1;

    while (running == 1) {
        running = menu(running);
    }

    return 0;
}