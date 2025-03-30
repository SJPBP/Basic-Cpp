//
// Created by user on 10/4/23.
//

#ifndef LAB___4_DIVSALES_H
#define LAB___4_DIVSALES_H


// Declaration of the DivSales class for the *.h file
class DivSales
{
    private:
        static double corpSales;
        double divSales;

    public:
        double qtrs[4];

        void setDivSales(double s)
        { divSales = divSales + s; }

        void setCorpSales(double s)
        { corpSales = corpSales + s; }

        double getDivSales() const
        { return divSales; }

        double getCorpSales() const
        { return corpSales; }
};

// Static member variable definition
double DivSales::corpSales;


#endif //LAB___4_DIVSALES_H
