#include <iostream>
using namespace std;
class Shape
{
public:
    virtual float area() = 0;
};
class Circle: public Shape
{
public:
    float r;
    Circle(float radius)
    {
        r = radius;
    }
    float area()
    {
        return 3.14 * r * r;
    }
};
class Rectangle: public Shape
{
public:
    float l,b;
    Rectangle(float length,float breadth)
    {
        l = length;
        b = breadth;
    }
    float area()
    {
        return l * b;
    }
};
class Triangle: public Shape
{
public:
    float b,h;
    Triangle(float base,float height)
    {
        b = base;
        h = height;
    }
    float area()
    {
        return 0.5 * b * h;
    }
};
int main()
{
    Circle c(5);
    Rectangle r(4,6);
    Triangle t(4,5);

    Shape *s;
    s = &c;
    cout << "Circle Area: " << s->area() << endl;

    s = &r;
    cout << "Rectangle Area: " << s->area() << endl;

    s = &t;
    cout << "Triangle Area: " << s->area() << endl;

    return 0;
}
