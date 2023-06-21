#define _USE_MATH_DEFINES
#include "shape.h"
#include <cmath>

Shape::Shape(ShapeType type, int x1, int y1, int z1, int x2, int y2, int z2,
             int x3, int y3, int z3, int x4, int y4, int z4,
             int x5, int y5, int z5, int x6, int y6, int z6,
             int x7, int y7, int z7, int x8, int y8, int z8)
    : type(type)
{
    coordinates[0][0] = x1;
    coordinates[0][1] = y1;
    coordinates[0][2] = z1;
    coordinates[1][0] = x2;
    coordinates[1][1] = y2;
    coordinates[1][2] = z2;
    coordinates[2][0] = x3;
    coordinates[2][1] = y3;
    coordinates[2][2] = z3;
    coordinates[3][0] = x4;
    coordinates[3][1] = y4;
    coordinates[3][2] = z4;
    coordinates[4][0] = x5;
    coordinates[4][1] = y5;
    coordinates[4][2] = z5;
    coordinates[5][0] = x6;
    coordinates[5][1] = y6;
    coordinates[5][2] = z6;
    coordinates[6][0] = x7;
    coordinates[6][1] = y7;
    coordinates[6][2] = z7;
    coordinates[7][0] = x8;
    coordinates[7][1] = y8;
    coordinates[7][2] = z8;
}

// Методы класса Shape
// ...
