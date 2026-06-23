#include "area.h"

void input() {
    printf("Available Units\n");
    printf("1) Milimeters\n");
    printf("2) Centimeters\n");
    printf("3) Meters\n");
    printf("4) Kilometers\n\n");

    printf("Width => "); scanf("%lf", &width);
    printf("Height => "); scanf("%lf", &height);
    printf("Units => "); scanf("%d", &origUnits);

    convert(width, height, origUnits); 

}

int calculate(int width, int height) {
    return width * height;
}

void convert(int height, int width, int origUnits) {
    printf("What do you wish to convert your units to?\n");
    printf("1) Milimeters\n");
    printf("2) Centimeters\n");
    printf("3) Meters\n");
    printf("4) Kilometers\n");
    printf("Convert to => "); scanf("%d", &toConvert);



    // Converting into meters
    if (origUnits == 1) {
        height = height / 1000;
        width = width / 1000;
    } else if (origUnits == 2) {
        height = height / 100;
        width = width / 100;
    } else if (origUnits == 4) {
        height = height * 1000;
        width = width * 1000;
    }

    if (toConvert == 1) {
        width = width * 1000;
        height = height * 1000;
    } else if (toConvert == 2) {
        width = width * 100;
        height = height * 100;
    } else if (toConvert == 4) {
        width = width / 1000;
        height = height / 1000;
    }
    
    area = calculate(width, height);
}

int main(void) {
    input();

    if (area > 0) {
        printf("Area => %Lf\n", area);
    } else {
        printf("Area => %.10Lf\n", area);
    }

    return 0;
}