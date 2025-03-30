//
// Created by user on 10/31/23.
//

#ifndef LAB__9_GASPRICE_H
#define LAB__9_GASPRICE_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class GasPrice
{
    private:
        string Day;
        string Month;
        string Year;
        double Price;

    public:
        GasPrice()
        {};

        GasPrice(string d, string m, string y, double p)
        {
            Day = d;
            Month = m;
            Year = y;
            Price = p;
        }

        void setDay(string d)
        { Day = d; }

        void setMonth(string m)
        { Month = m; }

        void setYear(string y)
        { Year = y; }

        void setPrice(double p)
        { Price = p; }

        string getYear() const
        { return Year; }

        double getPrice() const
        { return Price; }
};
#endif //LAB__9_GASPRICE_H
