#include "transform.h"

Transform::Transform(Shape* shape)
    : shape(shape)
{
}

void Transform::shift(int offsetX, int offsetY, int offsetZ)
{
    for (int i = 0; i < 8; ++i)
    {
        int x = shape->getCoordinate(i, 0);
        int y = shape->getCoordinate(i, 1);
        int z = shape->getCoordinate(i, 2);

        x += offsetX;
        y += offsetY;
        z += offsetZ;

        shape->setCoordinate(i, 0, x);
        shape->setCoordinate(i, 1, y);
        shape->setCoordinate(i, 2, z);
    }
}

void Transform::scaleX(int scale)
{
    for (int i = 0; i < 8; ++i)
    {
        int x = shape->getCoordinate(i, 0);
        x *= scale;
        shape->setCoordinate(i, 0, x);
    }
}

void Transform::scaleY(int scale)
{
    for (int i = 0; i < 8; ++i)
    {
        int y = shape->getCoordinate(i, 1);
        y *= scale;
        shape->setCoordinate(i, 1, y);
    }
}

void Transform::scaleZ(int scale)
{
    for (int i = 0; i < 8; ++i)
    {
        int z = shape->getCoordinate(i, 2);
        z *= scale;
        shape->setCoordinate(i, 2, z);
    }
}

void Transform::scale(int scale)
{
    for (int i = 0; i < 8; ++i)
    {
        int x = shape->getCoordinate(i, 0);
        int y = shape->getCoordinate(i, 1);
        int z = shape->getCoordinate(i, 2);

        x *= scale;
        y *= scale;
        z *= scale;

        shape->setCoordinate(i, 0, x);
        shape->setCoordinate(i, 1, y);
        shape->setCoordinate(i, 2, z);
    }
}
