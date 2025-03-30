#include<iostream>
using namespace std;

template <typename T>
T one_third(T num)
{
    return num / 3;
}

int main() {

    int iVal, iThird;
    double dVal, dThird;

    char response = 'Y';

    while(response == 'Y' or response == 'y')
    {
        cout << "\nEnter an integer: ";
        cin >> iVal;

        iThird = one_third(iVal);
        cout << "One third of " << iVal << " is " << iThird << endl;

        cout << "\nEnter a double: ";
        cin >> dVal;

        dThird = one_third(dVal);
        cout << "One third of " << dVal << " is " << dThird << endl;

        cout << "\nDo you want to contiune? (Y or y) or 0 to Quit!\t";
        cin >> response;

    }

    return 0;
}
