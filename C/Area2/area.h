#ifndef AREA_H

#include <stdio.h>

#define MM_TO_CM 10
#define MM_TO_M  1000
#define MM_TO_KM 1000000

#define CM_TO_MM 10
#define CM_TO_M  100
#define CM_TO_KM 1000000

#define M_TO_MM  1000
#define M_TO_CM  100
#define M_TO_KM  1000

#define KM_TO_M  1000
#define KM_TO_CM 100000
#define KM_TO_MM 1000000

typedef enum {
    MM = 1,
    CM,
    M,
    KM
} Unit;


typedef struct{
    double width;
    double height;
    long double area;
    Unit unit;
    Unit toConvert;
} Rectangle;

Rectangle getInput(Rectangle rect);
Rectangle convertRectangle(Rectangle rect);
void printArea(Rectangle rect);


#endif