#define _USE_MATH_DEFINES
#include "shape.h"
#include <cmath>

Line::Line(int x1, int y1, int z1, int x2, int y2, int z2) {
    coordinates[0][0] = x1;
    coordinates[0][1] = y1;
    coordinates[0][2] = z1;
    coordinates[1][0] = x2;
    coordinates[1][1] = y2;
    coordinates[1][2] = z2;
}

double Line::calculateSquare() const {
    return 0;
}

double Line::calculateVolume() const {
    return 0;
}

Rectangle::Rectangle(int x1, int y1, int z1, int x2, int y2, int z2, 
                     int x3, int y3, int z3, int x4, int y4, int z4) {
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
}

double Rectangle::calculateSquare() const {
    int a = std::abs(coordinates[0][0] - coordinates[1][0]);
    int b = std::abs(coordinates[0][1] - coordinates[1][1]);
    return a * b;
}

double Rectangle::calculateVolume() const {
    return 0;
}

Parallelepiped::Parallelepiped(int x1, int y1, int z1, int x2, int y2, int z2,
                               int x3, int y3, int z3, int x4, int y4, int z4,
                               int x5, int y5, int z5, int x6, int y6, int z6,
                               int x7, int y7, int z7, int x8, int y8, int z8) {
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

double Parallelepiped::calculateSquare() const {
    int a = std::abs(coordinates[0][0] - coordinates[1][0]);
    int b = std::abs(coordinates[0][1] - coordinates[1][1]);
    int c = std::abs(coordinates[0][2] - coordinates[1][2]);
    return 2 * (a * b + a * c + b * c);
}

double Parallelepiped::calculateVolume() const {
    int a = std::abs(coordinates[0][0] - coordinates[1][0]);
    int b = std::abs(coordinates[0][1] - coordinates[1][1]);
    int c = std::abs(coordinates[0][2] - coordinates[1][2]);
    return a * b * c;
}
int Line::getCoordinate(int index, int axis) const {
    return coordinates[index][axis];
}

void Line::setCoordinate(int index, int axis, int value) {
    coordinates[index][axis] = value;
}

int Rectangle::getCoordinate(int index, int axis) const {
    return coordinates[index][axis];
}

void Rectangle::setCoordinate(int index, int axis, int value) {
    coordinates[index][axis] = value;
}

int Parallelepiped::getCoordinate(int index, int axis) const {
    return coordinates[index][axis];
}

void Parallelepiped::setCoordinate(int index, int axis, int value) {
    coordinates[index][axis] = value;
}
