#include "transform.h"

Transform::Transform(const Shape& shape)
    : shape(shape)
{
}

Shape Transform::shift(int offsetX, int offsetY, int offsetZ)
{
    for (int i = 0; i < 8; ++i)
    {
        shape.coordinates[i][0] += offsetX;
        shape.coordinates[i][1] += offsetY;
        shape.coordinates[i][2] += offsetZ;
    }
    return shape;
}

// Методы класса Transform
// ...
