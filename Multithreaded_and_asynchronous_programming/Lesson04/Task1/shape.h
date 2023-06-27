#pragma once

class Shape
{
public:
    virtual double calculateSquare() const = 0;
    virtual double calculateVolume() const = 0;
    virtual int getCoordinate(int index, int axis) const = 0;
    virtual void setCoordinate(int index, int axis, int value) = 0;
};

class Line : public Shape
{
public:
    Line(int x1, int y1, int z1, int x2, int y2, int z2);
    virtual double calculateSquare() const override;
    virtual double calculateVolume() const override;
    virtual int getCoordinate(int index, int axis) const override;
    virtual void setCoordinate(int index, int axis, int value) override;

private:
    int coordinates[2][3];
};

class Rectangle : public Shape
{
public:
    Rectangle(int x1, int y1, int z1, int x2, int y2, int z2, 
              int x3, int y3, int z3, int x4, int y4, int z4);
    virtual double calculateSquare() const override;
    virtual double calculateVolume() const override;
    virtual int getCoordinate(int index, int axis) const override;
    virtual void setCoordinate(int index, int axis, int value) override;

private:
    int coordinates[4][3];
};

class Parallelepiped : public Shape
{
public:
    Parallelepiped(int x1, int y1, int z1, int x2, int y2, int z2,
                   int x3, int y3, int z3, int x4, int y4, int z4,
                   int x5, int y5, int z5, int x6, int y6, int z6,
                   int x7, int y7, int z7, int x8, int y8, int z8);
    virtual double calculateSquare() const override;
    virtual double calculateVolume() const override;
    virtual int getCoordinate(int index, int axis) const override;
    virtual void setCoordinate(int index, int axis, int value) override;

private:
    int coordinates[8][3];
};

