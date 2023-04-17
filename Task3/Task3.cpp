#include <iostream>
#include <string>

class Figure {
public:
    Figure() : Figure(0) {
    }

    Figure(unsigned sides) : sides(sides) {
        fname = "Фигура";
    }

    unsigned getSides() {
        return sides;
    }

    virtual void print_info() {
        std::cout << fname << ':' << std::endl <<
            (check() ? "Правильная" : "Неправильная") << std::endl <<
            "Количество сторон: " << sides << std::endl;
    }

    virtual bool check() {
        return (sides == 0);
    }
protected:
    unsigned sides;
    std::string fname;
};

//Треугольник
class Triangle : public Figure {
public:
    Triangle() : Triangle(50, 60, 70, 10, 20, 30) {
    }

    Triangle(int A, int B, int C, int a, int b, int c) : Figure(3) {
        this->A = A;
        this->B = B;
        this->C = C;
        this->a = a;
        this->b = b;
        this->c = c;
        fname = "Треугольник";
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

    void print_info() {
        Figure::print_info();
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << '\n' <<
            "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << '\n' << '\n';
    }
    bool check() {
        return ((A + B + C == 180) && (sides == 3));
    }

protected:
    int A, B, C; //angles
    int a, b, c; //sides lenght
};

//Четырёхугольник
class Quadrilateral : public Figure {
public:
    Quadrilateral() : Quadrilateral(50, 60, 70, 80, 10, 20, 30, 40) {
    }

    Quadrilateral(int A, int B, int C, int D, int a, int b, int c, int d) : Figure(4) {
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        fname = "Четырёхугольник";
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
    void print_info() {
        Figure::print_info();
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << '\n'
            << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << '\n' << '\n';
    }
    bool check() {
        return ((A + B + C + D == 360) && (sides == 4));
    }

protected:
    int A, B, C, D; //angles
    int a, b, c, d; //sides lenght
};

//Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle() : RightTriangle(30, 60, 90, 10, 20, 30) {
    }
    RightTriangle(int A, int B, int C, int a, int b, int c) : Triangle(A, B, C, a, b, c) {
        fname = "Прямоугольный треугольник";
    }
    bool check() {
        return (Triangle::check() && C == 90);
    }
};

//Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() : IsoscelesTriangle(50, 60, 10, 20) {

    }

    IsoscelesTriangle(int angle_AC, int angle_B, int side_ac, int side_b) : Triangle(angle_AC, angle_B, angle_AC, side_ac, side_b, side_ac) {
        fname = "Равнобедренный треугольник";
    }

    bool check() {
        return (Triangle::check() && a == c && A == C);
    }
};

//Равносторонний треугольник
class EquilateralTriangle : public IsoscelesTriangle {
public:
    EquilateralTriangle() : EquilateralTriangle(30) {

    }

    EquilateralTriangle(int sides_abc) : IsoscelesTriangle(60, 60, sides_abc, sides_abc) {
        fname = "Равносторонний треугольник";
    }
    bool check() {
        return (Triangle::check() && a == b && A == 60 && B == 60);
    }
};

//Параллелограмм
class Parallelogram : public Quadrilateral {
public:
    Parallelogram() : Parallelogram(30, 40, 20, 30) {

    }

    Parallelogram(int angle_AC, int angle_BD, int sides_ac, int sides_bd)
        : Quadrilateral(angle_AC, angle_BD, angle_AC, angle_BD, sides_ac, sides_bd, sides_ac, sides_bd) {

        fname = "Параллелограмм";

    }

    bool check() {
        return (Quadrilateral::check() && a == c && b == d && A == C && B == D);
    }
};

//Ромб
class Rhomb : public Parallelogram {
public:
    Rhomb() : Rhomb(30, 40, 30) {
    }
    Rhomb(int angle_AC, int angle_BD, int sides_abcd) : Parallelogram(angle_AC, angle_BD, sides_abcd, sides_abcd) {
        fname = "Ромб";
    }

    bool check() {
        return (Parallelogram::check() && a == b);
    }
};

//Прямоугольник
class Rectangle : public Parallelogram {
public:
    Rectangle() : Rectangle(10, 20) {

    }

    Rectangle(int sides_ac, int sides_bd) : Parallelogram(90, 90, sides_ac, sides_bd) {
        fname = "Прямоугольник";
    }
    bool check() {
        return (Parallelogram::check() && A == 90 && B == 90);
    }
};

//Квадрат
class Square : public Rectangle {
public:
    Square() : Square(20) {
        fname = "Квадрат";
    }
    Square(int sideABCD) : Rectangle(sideABCD, sideABCD) {
        fname = "Квадрат";
    }

    bool check() {
        return (Rectangle::check() && a == b);
    }
};

int main() {
    std::setlocale(LC_ALL, "Russian");

    Figure* figure;
    Triangle triangle;
    RightTriangle righttriangle_wrong(50, 60, 80, 10, 20, 30);
    RightTriangle righttriangle_right;
    IsoscelesTriangle isoscelestriangle_wrong;
    IsoscelesTriangle isoscelestriangle_right(30, 120, 20, 30);
    EquilateralTriangle equilateraltriangle;
    Quadrilateral quadrilateral_wrong;
    Quadrilateral quadrilateral_right(50, 70, 80, 160, 10, 15, 20, 30);
    Rectangle rectangle;
    Square square;
    Parallelogram parallelogram_wrong;
    Parallelogram parallelogram_right(80, 100, 15, 25);
    Rhomb rhomb_wrong;
    Rhomb rhomb_right(70, 110, 50);
    figure = &triangle;
    figure->print_info();
    figure = &righttriangle_wrong;
    figure->print_info();
    figure = &righttriangle_right;
    figure->print_info();
    figure = &isoscelestriangle_wrong;
    figure->print_info();
    figure = &isoscelestriangle_right;
    figure->print_info();
    figure = &equilateraltriangle;
    figure->print_info();
    figure = &quadrilateral_wrong;
    figure->print_info();
    figure = &quadrilateral_right;
    figure->print_info();
    figure = &rectangle;
    figure->print_info();
    figure = &square;
    figure->print_info();
    figure = &parallelogram_wrong;
    figure->print_info();
    figure = &parallelogram_right;
    figure->print_info();
    figure = &rhomb_wrong;
    figure->print_info();
    figure = &rhomb_right;
    figure->print_info();
}