#include <iostream>
#include <iomanip>
#include "Circle.h"

using namespace std;
int main()
{
    double radius = 0; // To hold a radius

    // Get the radius.
    while (radius <= 0)
    {
        cout << "Enter the circle's radius: ";
        cin >> radius;

        if (radius <= 0) {
            cout << "That is not a valid radius." << endl << endl;

        }
    }

    Circle userCircle(radius); // Create a Circle object with the specified radius.

    cout << setprecision(2) << fixed;

    // Display the circle's data.
    cout << "Radius: " << userCircle.getRadius() << endl;
    cout << "Area : " << userCircle.getArea() << endl;
    cout << "Diameter: " << userCircle.getDiameter() << endl;
    cout << "Circumference: " << userCircle.getCircumference() << endl;

    return 0;
}
// UML Diagram as a comment below main per Figure 13-24
// **********************************
// Circle
// **********************************
// MEMBER VARIABLES
//  - Radius : double
//  - Pi : double
// **********************************
// MEMBER FUNCTIONS
//  + Circle() : void
//  + Circle(double) : void
//  + setRadius(double) : void
//  + getArea() : double
//  + getDiameter() : double
//  + getCircumference() : double
//  + getRadius() : double
// **********************************
