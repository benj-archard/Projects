#include "area.h"

Rectangle getInput(Rectangle rect) {
    int unitInput;

    printf("Possible units\n");
    printf("1) Milimeters\n");
    printf("2) Centimeters\n");
    printf("3) Meters\n");
    printf("4) Kilometers\n");


    printf("Width: "); scanf("%lf", &rect.width);
    printf("Height: "); scanf("%lf", &rect.height);


    // Validate entry
    while (rect.width < 0 || rect.height < 0) {
        if (rect.width < 0) {
            printf("Invalid width input, input must be a number and must be positive\n");
            printf("Width: "); scanf("%lf", &rect.width);
        } else if (rect.height < 0) {
            printf("Invalid height input, input must be number and must be positive\n");
            printf("Height: "); scanf("%lf", &rect.height);
        }
    }

    printf("Unit => "); scanf("%d", &unitInput);

    // Validate entry
    while (unitInput < MM || unitInput > KM) {
        printf("Invalid unit input!. Please select a unit by inputting 1,2,3 or 4\n");
        printf("Unit => "); scanf("%d", &unitInput);
    }

    rect.unit = (Unit)unitInput;

    printf("What would you like to convert to?: "); scanf("%d", &unitInput);

    rect.toConvert = (Unit)unitInput;

    return rect;
} 

Rectangle convertRectangle(Rectangle rect) {

    if (rect.unit == MM) {
        if (rect.toConvert == CM) {
            rect.width = rect.width / MM_TO_CM;
            rect.height = rect.height / MM_TO_CM;
        } else if (rect.toConvert == M) {
            rect.width = rect.width / MM_TO_M;
            rect.height = rect.height / MM_TO_M;
        } else if (rect.toConvert == KM) {
            rect.width = rect.width / MM_TO_KM;
            rect.height = rect.height / MM_TO_KM;
        }
    } else if (rect.unit == CM) {
        if (rect.toConvert == MM) {
            rect.width = rect.width * CM_TO_MM;
            rect.height = rect.height * CM_TO_MM;
        }
        if (rect.toConvert == M) {
            rect.width = rect.width / CM_TO_M;
            rect.height = rect.height / CM_TO_M;
        } else if (rect.toConvert == KM) {
            rect.width = rect.width / CM_TO_KM;
            rect.height = rect.height / CM_TO_KM;
        }
    } else if (rect.unit == M) {
        if (rect.toConvert == MM) {
            rect.width = rect.width * M_TO_MM;
            rect.height = rect.height * M_TO_MM;
        } else if (rect.toConvert == CM) {
            rect.width = rect.width * M_TO_CM;
            rect.height = rect.height * M_TO_CM;
        } else if (rect.toConvert == KM) {
            rect.width = rect.width / M_TO_KM;
            rect.height = rect.height / M_TO_KM;
        }
    } else if (rect.unit == KM) {
        if (rect.toConvert == MM) {
            rect.width = rect.width * KM_TO_MM;
            rect.height = rect.height * KM_TO_MM;
        } else if (rect.toConvert == CM) {
            rect.width = rect.width * KM_TO_CM;
            rect.height = rect.height * KM_TO_CM;
        } else if (rect.toConvert == M) {
            rect.width = rect.width * KM_TO_M;
            rect.height = rect.height * KM_TO_M;
        }
    }

    return rect;
}

void printArea(Rectangle rect) {

    rect.area = rect.width * rect.height;

    printf("Area => %.8Lf\n", rect.area);
}

int main(void) {
    Rectangle rect;

    rect = getInput(rect);
    rect = convertRectangle(rect);
    printArea(rect);

    return 0;
}