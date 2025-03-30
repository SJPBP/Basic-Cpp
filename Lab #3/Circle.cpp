#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle()
{
    Radius = 0.0;
    Pi = 3.14159;
}

Circle::Circle(double r)
{
    Radius = r;
    Pi = 3.14159;
}

void Circle::setRadius(double r)
{
    Radius = r;
}

double Circle::getArea() const
{
    return Pi * Radius * Radius;
}

double Circle::getDiameter() const
{
    return Radius * 2;
}

double Circle::getCircumference() const
{
    return 2 * Pi * Radius;
}


