#include <iostream>
#include <iomanip>
#include "Circle.h"

using namespace std;

int main()
{
    double radius = 0; // To hold a radius
    char tryAgain = 'y';

    Circle userCircle;

    while(tryAgain == 'y' || tryAgain == 'Y')
    {
        cout << "Enter the circle's radius: ";
        cin >> radius;
        try
        {
            userCircle.setRadius(radius);
            cout << setprecision(2) << fixed;
            cout << "Radius: " << userCircle.getRadius() << endl;
            cout << "Area : " << userCircle.getArea() << endl;
            cout << "Diameter: " << userCircle.getDiameter() << endl;
            cout << "Circumference: " << userCircle.getCircumference() << endl << endl;
        }
        catch (Circle::NegativeRadius e)
        {
            cout << "Error: " << e.getValue() << " is not a valid radius." << endl <<endl;
        }
        cout << "Enter Y to run again:";
        cin >> tryAgain;
    }
    return 0;
}