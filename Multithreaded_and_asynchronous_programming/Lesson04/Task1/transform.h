#pragma once
#include "shape.h"

class Transform
{
public:
    Transform(const Shape& shape);
    Shape shift(int offsetX, int offsetY, int offsetZ);
    // Заголовки остальных методов класса Transform
    // ...
private:
    Shape shape;
};

// Заголовки остальных методов класса Transform
// ...
