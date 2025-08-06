#include<iostream>
using namespace std;

class Shape {
public:
    Shape() {}
    virtual double Area() = 0; // Pure virtual function
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double Area() override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double Area() override {
        return 3.14 * radius * radius;
    }
};

int main() {
    Shape* shape;
    // for the area of rectangle
    Rectangle rectangle(2, 3);
    shape = &rectangle;

    // for the area of circle
    Circle circle(3);
    shape = &circle;

    cout << "Area: " << shape->Area() << endl;

    return 0;
}