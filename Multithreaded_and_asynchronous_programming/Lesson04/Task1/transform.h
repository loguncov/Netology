#pragma once
#include "shape.h"

class Transform
{
public:
    Transform(Shape* shape);
    void shift(int offsetX, int offsetY, int offsetZ);
    void scaleX(int scale);
    void scaleY(int scale);
    void scaleZ(int scale);
    void scale(int scale);

private:
    Shape* shape;
};
