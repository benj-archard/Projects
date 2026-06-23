#ifndef AREA_H
#define AREA_H

#define MM_TO_CM 10
#define MM_TO_M  1000
#define MM_TO_KM 1000000

#define CM_TO_M  100
#define CM_TO_KM 10000

#define M_TO_KM  1000

#include <stdio.h>

double height = 0, width = 0;
long double area;
int origUnits = 0, toConvert = 0;

void input(void);
void convert(int width ,int height, int origUnits);
int calculate(int width, int height);

#endif