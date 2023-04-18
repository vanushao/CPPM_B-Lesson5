#include <iostream>
#include <string>

class Figure {
public:
    Figure():Figure(0) {
    }
    Figure(unsigned sides) : sides(sides) {
        name = "Фигура";
    }

    unsigned getSides() {
        return sides;
    }
    std::string getName() {
        return name;
    }

protected:

    unsigned sides;
    std::string name;

};

class Triangle : public Figure {
public:
    Triangle() : Figure(3) {
        name = "Треугольник";
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral() : Figure(4) {
        name = "Четырёхугольник";
    }
};

int main() {
    std::setlocale(LC_ALL, "Russian");

    Figure figure;
    Triangle triangle;
    Quadrilateral quadrilateral;

    std::cout << "Количество сторон:" << std::endl <<
        figure.getName() << ": " << figure.getSides() << std::endl <<
        triangle.getName() << ": " << triangle.getSides() << std::endl <<
        quadrilateral.getName() << ": " << quadrilateral.getSides() << std::endl;

}