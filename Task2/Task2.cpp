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

//Треугольник
class Triangle : public Figure {
public:
    Triangle() : Triangle(50, 60, 70, 10, 20, 30) {
    }

    int get_A() {
        return A;
    }
    int get_B() {
        return B;
    }
    int get_C() {
        return C;
    }

    int get_a() {
        return a;
    }
    int get_b() {
        return b;
    }
    int get_c() {
        return c;
    }

protected:
    Triangle(int A, int B, int C, int a, int b, int c) : Figure(3) {
        this->A = A;
        this->B = B;
        this->C = C;
        this->a = a;
        this->b = b;
        this->c = c;
    }
    int A, B, C; //angles
    int a, b, c; //sides lenght
};

//Четырёхугольник
class Quadrilateral : public Figure {
public:
    Quadrilateral() : Quadrilateral(50, 60, 70, 80, 10, 20, 30, 40) {
    }

    int get_A() {
        return A;
    }
    int get_B() {
        return B;
    }
    int get_C() {
        return C;
    }
    int get_D() {
        return D;
    }

    int get_a() {
        return a;
    }
    int get_b() {
        return b;
    }
    int get_c() {
        return c;
    }
    int get_d() {
        return d;
    }

protected:
    Quadrilateral(int A, int B, int C, int D, int a, int b, int c, int d) : Figure(4) {
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    int A, B, C, D; //angles
    int a, b, c, d; //sides lenght
};

//Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle() : Triangle(50, 60, 90, 10, 20, 30) {

    }
};

//Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() : IsoscelesTriangle(50, 60, 10, 20) {

    }
protected:
    IsoscelesTriangle(int angle_AC, int angle_B, int side_ac, int side_b) : Triangle(angle_AC, angle_B, angle_AC, side_ac, side_b, side_ac) {

    }
};

//Равносторонний треугольник
class EquilateralTriangle : public IsoscelesTriangle {
public:
    EquilateralTriangle() : EquilateralTriangle(30) {

    }
protected:
    EquilateralTriangle(int sides_abc) : IsoscelesTriangle(60, 60, sides_abc, sides_abc) {

    }
};

//Параллелограмм
class Parallelogram : public Quadrilateral {
public:
    Parallelogram() : Parallelogram(30, 40, 20, 30) {

    }
protected:
    Parallelogram(int angle_AC, int angle_BD, int sides_ac, int sides_bd)
        : Quadrilateral(angle_AC, angle_BD, angle_AC, angle_BD, sides_ac, sides_bd, sides_ac, sides_bd) {

    }
};

//Ромб
class Rhomb : public Parallelogram {
public:
    Rhomb() : Parallelogram(30, 40, 30, 30) {

    }
};

//Прямоугольник
class Rectangle : public Parallelogram {
public:
    Rectangle() : Rectangle(10, 20) {

    }
protected:
    Rectangle(int sides_ac, int sides_bd) : Parallelogram(90, 90, sides_ac, sides_bd) {

    }
};

//Квадрат
class Square : public Rectangle {
public:
    Square() : Rectangle(20, 20) {

    }
};

std::ostream& operator<<(std::ostream& out, Triangle& t) {
    out << "Стороны: a=" << t.get_a() << " b=" << t.get_b() << " c=" << t.get_c() << '\n'
        << "Углы: A=" << t.get_A() << " B=" << t.get_B() << " C=" << t.get_C() << '\n';
    return out;
}

std::ostream& operator<<(std::ostream& out, Quadrilateral& q) {
    out << "Стороны: a=" << q.get_a() << " b=" << q.get_b() << " c=" << q.get_c() << " d=" << q.get_d() << '\n'
        << "Углы: A=" << q.get_A() << " B=" << q.get_B() << " C=" << q.get_C() << " D=" << q.get_D() << '\n';
    return out;
}


int main() {
    std::setlocale(LC_ALL, "Russian");

    Triangle triangle;
    RightTriangle righttriangle;
    IsoscelesTriangle isoscelestriangle;
    EquilateralTriangle equilateraltriangle;
    Quadrilateral quadrilateral;
    Rectangle rectangle;
    Square square;
    Parallelogram parallelogram;
    Rhomb rhomb;

    std::cout << "Треугольник:" << std::endl << triangle << std::endl
        << "Прямоугольный треугольник:" << std::endl << righttriangle << std::endl
        << "Равнобедренный треугольник:" << std::endl << isoscelestriangle << std::endl
        << "Равносторонний треугольник:" << std::endl << equilateraltriangle << std::endl
        << "Четырёхугольник:" << std::endl << quadrilateral << std::endl
        << "Прямоугольник:" << std::endl << rectangle << std::endl
        << "Квадрат:" << std::endl << square << std::endl
        << "Параллелограмм:" << std::endl << parallelogram << std::endl
        << "Ромб:" << std::endl << rhomb << std::endl;

}