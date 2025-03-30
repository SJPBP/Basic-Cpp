#include <iostream>
#include "Ship.h"

using namespace std;

int main() {
    // Create an array of Ship pointers, initialized with the addresses of 3 dynamically allocated objects.
    Ship *ships[3] = { new Ship("Lolipop", "1960"),
                       new CruiseShip("Disney Magic", "1998", 2400),
                       new CargoShip("Black Pearl", "1800", 50000)
    };
    // Call each object's print function.
    for (int index=0; index < 3; index++)
    {
        ships[index] -> print();
        cout << "----------------------------\n";
    }
    return 0;
}
