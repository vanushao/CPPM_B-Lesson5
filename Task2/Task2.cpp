#include <iostream>
#include <string>

class Figure {
public:
    Figure() :Figure(0) {
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

    virtual std::string getinfo() {
        return (name + ": " + '\n');
    }

protected:
    unsigned sides;
    std::string name;
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
        name = "Треугольник";
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

    std::string getinfo() {
        std::string out = Figure::getinfo() + "Стороны: a=" + std::to_string(get_a()) + " b=" + std::to_string(get_b()) + " c=" + std::to_string(get_c()) + '\n'
            + "Углы: A=" + std::to_string(get_A()) + " B=" + std::to_string(get_B()) + " C=" + std::to_string(get_C()) + '\n';
        return out;
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
        name = "Четырёхугольник";
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

    std::string getinfo() {
        std::string out = Figure::getinfo() + "Стороны: a=" + std::to_string(get_a()) + " b=" + std::to_string(get_b()) + " c=" + std::to_string(get_c()) + " d=" + std::to_string(get_d()) + '\n'
            + "Углы: A=" + std::to_string(get_A()) + " B=" + std::to_string(get_B()) + " C=" + std::to_string(get_C()) + " D=" + std::to_string(get_D()) + '\n';
        return out;
    }

protected:
    int A, B, C, D; //angles
    int a, b, c, d; //sides lenght
};

//Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle() : RightTriangle(50, 60, 10, 20, 30) {
     }

    RightTriangle(int angle_A, int angle_B, int side_a, int side_b, int side_c) : Triangle(angle_A, angle_B, 90, side_a, side_b, side_c) {
        name = "Прямоугольный треугольник";
    }
};

//Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() : IsoscelesTriangle(50, 60, 10, 20) {
    }
    IsoscelesTriangle(int angle_AC, int angle_B, int side_ac, int side_b) : Triangle(angle_AC, angle_B, angle_AC, side_ac, side_b, side_ac) {
        name = "Равнобедренный треугольник";
    }
};

//Равносторонний треугольник
class EquilateralTriangle : public IsoscelesTriangle {
public:
    EquilateralTriangle() : EquilateralTriangle(30) {
    }
    EquilateralTriangle(int sides_abc) : IsoscelesTriangle(60, 60, sides_abc, sides_abc) {
        name = "Равносторонний треугольник";
    }
};

//Параллелограмм
class Parallelogram : public Quadrilateral {
public:
    Parallelogram() : Parallelogram(30, 40, 20, 30) {
    }
    Parallelogram(int angle_AC, int angle_BD, int sides_ac, int sides_bd)
        : Quadrilateral(angle_AC, angle_BD, angle_AC, angle_BD, sides_ac, sides_bd, sides_ac, sides_bd) {
        name = "Параллелограмм";
    }
};

//Ромб
class Rhomb : public Parallelogram {
public:
    Rhomb() : Parallelogram(30, 40, 30, 30) {
    }
    Rhomb(int angle_AC, int angle_BD, int sides_abcd) : Parallelogram(angle_AC, angle_BD, sides_abcd, sides_abcd) {
        name = "Ромб";
    }
};

//Прямоугольник
class Rectangle : public Parallelogram {
public:
    Rectangle() : Rectangle(10, 20) {
    }
    Rectangle(int sides_ac, int sides_bd) : Parallelogram(90, 90, sides_ac, sides_bd) {
        name = "Прямоугольник";
    }
};

//Квадрат
class Square : public Rectangle {
public:
    Square() : Square(20) {
    }
    Square(int side_abcd) : Rectangle(side_abcd, side_abcd) {
        name = "Квадрат";
    }
};

std::ostream& operator<<(std::ostream& out, Figure& t) {
    out << t.getinfo();
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

    std::cout << triangle << std::endl
        << righttriangle << std::endl
        << isoscelestriangle << std::endl
        << equilateraltriangle << std::endl
        << quadrilateral << std::endl
        << rectangle << std::endl
        << square << std::endl
        << parallelogram << std::endl
        << rhomb << std::endl;

}