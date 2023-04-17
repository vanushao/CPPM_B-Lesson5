#include <iostream>

class Figure {
public:
    Figure() {
        sides = 0;
    }
    unsigned getSides() {
        return sides;
    }

protected:
    Figure(unsigned sides) : sides(sides) {

    }

    unsigned sides;
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3) {

    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral() : Figure(4) {

    }
};

int main() {
    std::setlocale(LC_ALL, "Russian");

    Figure figure;
    Triangle triangle;
    Quadrilateral quadrilateral;

    std::cout << "Количество сторон:" << std::endl <<
        "Фигура: " << figure.getSides() << std::endl <<
        "Треугольник: " << triangle.getSides() << std::endl <<
        "Четырёхугольник: " << quadrilateral.getSides() << std::endl;

}