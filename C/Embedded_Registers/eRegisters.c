#include "eRegisters.h"

int readInput(char inputBuffer[], int bufferSize) {
    int toReturn = 0;

    while (1) {
        fgets(inputBuffer, bufferSize, stdin);
        inputBuffer[strcspn(inputBuffer, "\n")] = '\0';

        if (sscanf(inputBuffer, "%d", &toReturn) == 1) {
            return toReturn;
        }

        printf("Unable to read input!, please try again\n");
        printf("=> ");
    }

}

void readBinary(uint8_t registers[], int registerToRead) {
    for (int i = 7; i >= 0; i--) {
        printf("%u", (registers[registerToRead] >> i) & 1U);

        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("=> %" PRIu32, registers[registerToRead]);
    printf("\n");
}

int menu(char inputBuffer[], uint8_t registers[]) {
    int choice = 0;
    system("clear");

    printf("Current Registers\n");

    for (int i = 0; i < NUM_REGISTERS; i++) {
        printf("[%d]: ", i);
        readBinary(registers, i);
    } 

    printf("\n1) Set Register Value\n");
    printf("2) Set Bit\n");
    printf("3) Clear Bit\n");
    printf("4) Toggle Bit\n");
    printf("5) Reset Register\n");
    printf("6) Exit\n");
    printf("\nCHOICE => ");
    choice = readInput(inputBuffer, MAX_CHARS);

    while (choice != SET && choice != SET_BIT 
           && choice != CLEAR_BIT && choice != TOGGLE_BIT 
           && choice != RESET && choice != EXIT) {

            printf("Invalid input!, please select between 1,2,3,4,5,6 and 7\n");
            printf("CHOICE => "); choice = readInput(inputBuffer, MAX_CHARS);
    }

    switch (choice) {
        case SET:
            setRegister(inputBuffer, registers);
            break;

        case SET_BIT:
            setBit(inputBuffer, registers);
            break;
        case CLEAR_BIT:
            clearBit(inputBuffer, registers);
            break;
        case TOGGLE_BIT:
            toggleBit(inputBuffer, registers);
            break;
        case RESET:
            resetRegister(inputBuffer, registers);
            break;
        case EXIT:
            return 0;
    }

    return 1;
}

void setRegister(char inputBuffer[], uint8_t registers[]) {
    int choice = 0, choice2 = 0;

    printf("\nWhich register would you like to set (0-7): ");
    choice = readInput(inputBuffer, MAX_CHARS);

    while (choice < 0 || choice > 7) {
        printf("Invalid selection!, selection must be between 0 and 7!\n");
        printf("\nWhich register would you like to set (0-7): ");
        choice = readInput(inputBuffer, MAX_CHARS);
    }

    printf("\nWhat would you like to set the register to (0-255) => ");
    choice2 = readInput(inputBuffer, MAX_CHARS);
    
    while (choice2 < 0 || choice2 > 255) {
        printf("Invalid assignment!, assignment must be between 0 and 255!\n");
        printf("\nWhat would you like to set the register to (0-255) => ");
        choice2 = readInput(inputBuffer, MAX_CHARS);
    }

    registers[choice] = choice2;
}

void resetRegister(char inputBuffer[], uint8_t registers[]) {
    int choice = 0;

    printf("Which register would you like to reset? (0-7): ");
    choice = readInput(inputBuffer, MAX_CHARS);

    while (choice < 0 || choice > 7) {
        printf("Invalid selection!, you must select a register between 0-7!\n");
        printf("Whcih register would you like to reset? (0-7): ");
        choice = readInput(inputBuffer, MAX_CHARS);
    } 

    registers[choice] = 0;
}

void setBit(char inputBuffer[], uint8_t registers[]) {
    int choice = 0, choice2 = 0;
    printf("Please select which register to modify (0-7): ");
    choice = readInput(inputBuffer, MAX_CHARS);

    while (choice < 0 || choice > 7) {
        printf("Invalid input!, you must select a register between 0-7!\n");
        printf("Please select which register to modify (0-7): ");
        choice = readInput(inputBuffer, MAX_CHARS);
    }

    printf("NOTE You are selecting the index of the bit, e.g. (Selecting 1 = Selecting the 2nd bit)\n");
    printf("Please select which bit to modify (0-7): ");
    choice2 = readInput(inputBuffer, MAX_CHARS);

    while (choice2 < 0 || choice2 > 7) {
        printf("Invalid input!, you must select a bit between 0-7!\n");
        printf("Please select which bit to modify (0-7): ");
        choice2 = readInput(inputBuffer, MAX_CHARS);
    }

    registers[choice]  |= (1U << choice2);
}

void clearBit(char inputBuffer[], uint8_t registers[]) {
    int choice = 0, choice2 = 0;

     printf("Which register would you like to modify? (0-7): ");
    choice = readInput(inputBuffer, MAX_CHARS);

    while (choice < 0 || choice > 7) {
        printf("Invalid input!, you must select a register between 0-7!\n");
        printf("Which register would you like to modify? (0-7): ");
        choice = readInput(inputBuffer, MAX_CHARS);
    }

    printf("Which bit in register %d would you like to clear? (0-7): ", choice);
    choice2 = readInput(inputBuffer, MAX_CHARS);

    while (choice2 < 0 || choice2 > 31) {
        printf("Invalid input!, you must select a bit between 0-31!\n");
        printf("Which bit in register %d would you like to clear? (0-7): ", choice);
        choice2 = readInput(inputBuffer, MAX_CHARS);
    }

    registers[choice] &= ~(1U << choice2);

}

void toggleBit(char inputBuffer[], uint8_t registers[]) {
    int choice = 0, choice2 = 0;

    printf("Which register would you like to modify? (0-7): ");
    choice = readInput(inputBuffer, MAX_CHARS);

    while (choice < 0 || choice > 7) {
        printf("Invalid input!, you must select a register between 0-7!\n");
        printf("Which register would you like to modify? (0-7): ");
        choice = readInput(inputBuffer, MAX_CHARS);
    }

    printf("Which bit in register %d would you like to toggle? (0-7): ", choice);
    choice2 = readInput(inputBuffer, MAX_CHARS);

    while (choice2 < 0 || choice2 > 31) {
        printf("Invalid input!, you must select a bit between 0-31!\n");
        printf("Which bit in register %d would you like to toggle? (0-7): ", choice);
        choice2 = readInput(inputBuffer, MAX_CHARS);
    }

    registers[choice] ^= (1U << choice2);
}

int main(void) {
    char inputBuffer[MAX_CHARS];
    int running = 1;

    uint8_t registers[NUM_REGISTERS] = {0};

    while (running == 1) {
        running = menu(inputBuffer, registers);
    }

    return 0;
}