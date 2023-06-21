#pragma once

enum class ShapeType { Line, Rectangle, Parallelepiped };

class Shape
{
public:
    Shape(ShapeType type, int x1, int y1, int z1, int x2, int y2, int z2,
          int x3 = 0, int y3 = 0, int z3 = 0, int x4 = 0, int y4 = 0, int z4 = 0,
          int x5 = 0, int y5 = 0, int z5 = 0, int x6 = 0, int y6 = 0, int z6 = 0,
          int x7 = 0, int y7 = 0, int z7 = 0, int x8 = 0, int y8 = 0, int z8 = 0);

    ShapeType getType() const { return type; }

private:
    ShapeType type;
    int coordinates[8][3]; // Массив для хранения координат вершин фигуры
};

// Заголовки методов класса Shape
// ...
