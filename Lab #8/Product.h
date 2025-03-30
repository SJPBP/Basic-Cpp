//
// Created by user on 10/23/23.
//

#ifndef LAB__8_PRODUCT_H
#define LAB__8_PRODUCT_H

#include<iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Product class definition for Product.h file
class Product
{
    private:
        string name;
        int units;
        double price;
        int reOrderPoint;

    public: // constructor
        Product(string n, double p, int u)
        {
            name = n;
            price = p;
            units = u;
            reOrderPoint = 3;
        }

        void setName(string n)
        { name = n; }

        void setPrice(double p)
        { price = p; }

        void setUnits(int u)
        { units = u; }

        void setReorderPoint(int r)
        { reOrderPoint = r; }

        string getName() const
        { return name; }

        double getPrice() const
        { return price; }

        int getUnits() const
        { return units; }

        int getReorderPoint() const
        { return reOrderPoint; }
};

#endif //LAB__8_PRODUCT_H
