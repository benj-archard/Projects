#include "vehicles.h"

int menu(Vehicle vArray[], int *vCount) {
    int choice = 0;

    printf("\n1) Create a new vehicle\n");
    printf("2) Show all vehicles\n");
    printf("3) Show one vehicle\n");
    printf("4) Move a vehicle\n");
    printf("5) Rename a vehicle\n");
    printf("6) Exit\n");
    printf("CHOICE => "); scanf("%d", &choice);

    while (choice != CREATE && choice != SHOW_ALL && choice != SHOW_ONE && choice != MOVE && choice != RENAME && choice != EXIT) {
        printf("Invalid input!, your input must be either 1,2,3 or 4!\n");
        printf("CHOICE => "); scanf("%d", &choice);
    }

    if (choice == CREATE) {
        if (*vCount != 10) {
            vArray[*vCount] = createVehicle(vCount);
            (*vCount)++;
        }
    } else if (choice == SHOW_ALL) {
        showVehicles(vArray, vCount);
    } else if (choice == SHOW_ONE) {
        showOneVehicle(vArray, vCount);
    } 
    else if (choice == MOVE) {
        moveVehicle(vArray, vCount);
    } else if (choice == RENAME) {
        renameVehicle(vArray, vCount);
    } 
    else if (choice == EXIT) {
        return 0;
    }
    return 1;
}

Vehicle createVehicle(int *vCount) {
    Vehicle temp;

    temp.id = *vCount;
    strcpy(temp.name, "To be named");
    temp.posX = rand() % 100;
    temp.posY = rand() % 100;

    return temp;
}

Vehicle* findVehicle(Vehicle vArray[], int *vCount, int id) {
    for (int i = 0; i < *vCount; i++) {
        if (vArray[i].id == id) {
            return &vArray[i];
        }
    }
    return NULL;
}

void showVehicles(Vehicle vArray[], int *vCount) {
    for (int i = 0; i < *vCount; i++) {
        printf("\nVehicle ID: %d\n", vArray[i].id);
        printf("Vehicle Name: %s\n", vArray[i].name);
        printf("Vehicle X: %d\n", vArray[i].posX);
        printf("Vehicle Y: %d\n", vArray[i].posY);
    }
}

void showOneVehicle(Vehicle vArray[], int *vCount) {
    Vehicle* selectedVehicle = NULL;
    int chosenVehicle = 0;

    printf("Select a vehicle from 0 to %d\n", *vCount - 1); scanf("%d", &chosenVehicle);

    selectedVehicle = findVehicle(vArray, vCount, chosenVehicle);

    printf("Vehicle ID: %d\n", selectedVehicle->id);
    printf("Vehicle Name: %s\n", selectedVehicle->name);
    printf("Vehicle X: %d\n", selectedVehicle->posX);
    printf("Vehicle Y: %d\n", selectedVehicle->posY);
}



void moveVehicle(Vehicle vArray[], int *vCount) {
    Vehicle* selectedVehicle = NULL;
    int chosenVehicle = 0;

    int changeX = 0, changeY = 0;
    printf("Select a vehicle to move\n");

    for (int i = 0; i < *vCount; i++) {
        printf("Vehicle ID: %d\n", vArray[i].id);
    }

    printf("Choice => "); scanf("%d", &chosenVehicle);

    while (chosenVehicle < 0 || chosenVehicle > *vCount) {
        printf("Invalid choice!, your selection must be between 0 and %d!\n", *vCount - 1);
        printf("Choice => "); scanf("%d", &chosenVehicle);
    }

    selectedVehicle = findVehicle(vArray, vCount, chosenVehicle);

    while (selectedVehicle == NULL) {
        printf("Vehicle not found!, please try again\n");
        printf("Choice => "); scanf("%d", &chosenVehicle);
        selectedVehicle = findVehicle(vArray, vCount, chosenVehicle);
    }



    printf("Current vehicle X: %d\n", selectedVehicle->posX);
    printf("Current vehicle Y: %d\n", selectedVehicle->posY);

    printf("Change X by: "); scanf("%d", &changeX);
    printf("Change Y by: "); scanf("%d", &changeY);

    while (selectedVehicle->posX - changeX < 0 || selectedVehicle->posY - changeY < 0) {
        printf("Invalid change!, your change in X and Y must not result in X or Y values less than 0!\n");

        printf("Change X by: "); scanf("%d", &changeX);
        printf("Change Y by: "); scanf("%d", &changeY);
    }

    if (changeX <= 0) {
        selectedVehicle->posX -= changeX;
    } 
    if (changeX >= 0) {
        selectedVehicle->posX += changeX;
    }

    if (changeY <= 0) {
        selectedVehicle->posY -= changeY;
    } 
    if (changeY >= 0) {
        selectedVehicle->posY += changeY;
    }
}

void renameVehicle(Vehicle vArray[], int *vCount) {
    Vehicle* selectedVehicle = NULL;
    int chosenVehicle = 0;
    char toName[50];

    printf("Select a vehicle from 0 to %d to rename\n", *vCount - 1); scanf("%d", &chosenVehicle);
    selectedVehicle = findVehicle(vArray, vCount, chosenVehicle);

    while (selectedVehicle == NULL) {
        printf("Unable to find the vehicle!, please try again\n");
        printf("Select a vehicle from 0 to %d to rename\n", *vCount - 1); scanf("%d", &chosenVehicle);
        selectedVehicle = findVehicle(vArray, vCount, chosenVehicle);
    }

    printf("What would you like to rename this vehicle to?: "); scanf("%s", &toName);
    strcpy(selectedVehicle->name, toName);
}

int main(void) {
    srand(time(0));
    Vehicle vehicles[10];
    int vehicleCount = 0;
    int running = 1;

    while (running == 1) {
        running = menu(vehicles, &vehicleCount);
    }


    return 0;
}