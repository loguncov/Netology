#pragma once
#include "shape.h"

class Transform
{
public:
    Transform(const Shape& shape);
    Shape shift(int offsetX, int offsetY, int offsetZ);
    Shape scaleX(int scale);
    Shape scaleY(int scale);
    Shape scaleZ(int scale);
    Shape scale(int scale);

private:
    Shape shape;
};

