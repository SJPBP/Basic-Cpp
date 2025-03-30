//
// Created by user on 10/9/23.
//

#ifndef LAB__5_SHIP_H
#define LAB__5_SHIP_H

using namespace std;

// Ship class
class Ship
{
    protected:
        string name; // Ship name
        string yearBuilt; // Year it was built

    public:
        // Constructor
        Ship(string n, string y)
        {
            name = n;
            yearBuilt = y;
        }

        // Accessors
        string getName()
        { return name; }

        string getYearBuilt()
        { return yearBuilt; }

        // print function
        virtual void print()
        {
            cout << "Name: " << name << endl
                 << "Year built: " << yearBuilt << endl;
        }
};

class CruiseShip : public Ship
{
    protected:
        int Max_passengers;

    public:
        // Constructor
        CruiseShip(string n, string y, int z) : Ship(n, y) {
            Max_passengers = z;
        }

        // Accessors
        int getPassengersAmount()
        { return Max_passengers; }

        // print function
        virtual void print()
        {
            cout << "Name: " << name << endl
                 << "Maximum passengers: " << Max_passengers << endl;
        }
};

class CargoShip : public Ship
{
    protected:
        int Cargo_capacity;

    public:
        // Constructor
        CargoShip(string n, string y, int z)  : Ship(n, y) {
            Cargo_capacity = z;
        }

        // Accessors
        int getCargoCapacity()
        { return Cargo_capacity; }

        // print function
        virtual void print()
        {
            cout << "Name: " << name << endl
                 << "Cargo capacity: " << Cargo_capacity << endl;
        }

};
#endif //LAB__5_SHIP_H
