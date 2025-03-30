#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include "GasPrice.h"

using namespace std;

string getWord(string &s, string delim);

double getLowestPrice(auto d) ;
double getHighestPrice(auto d);

double getAveragePrice(auto d);

int main() {
    // File containing Data of Gas prices over the years
    fstream gasPriceFile;

    // Variable used in this program
    string Day;
    string Month;
    string Year;
    double Price;

    // Using map to organize the Data recreated to year
    multimap<string, GasPrice> Data;
    set<string> yearCount;

    // Open the file
    gasPriceFile.open("GasPrices.txt");

    // Check file successfully opened
    if (gasPriceFile.fail()) {
        cout << "ERROR: File wasn't successfully opened!";
        exit(1);
    }

    // Variable used temporary for loop
    string Temp;
    string hyphen = "-";
    string colon = ":";

    // Loop through the file to obtain data
    while (getline(gasPriceFile, Temp)) {
        Day = getWord(Temp, hyphen);
        Month = getWord(Temp, hyphen);
        Year = getWord(Temp, hyphen);

        Price = stod(getWord(Temp, colon));

        GasPrice gasPriceObject(Day, Month, Year, Price);

        Data.emplace(Year, gasPriceObject);

        yearCount.insert(Year);
    }
    gasPriceFile.close();

    for (const auto& i : yearCount)
    {
        auto value = Data.equal_range(i);

        vector<double> price;

        for (auto itr = value.first; itr != value.second; ++itr)
        {
            auto first = itr->first;
            auto second = itr->second;

            price.push_back(second.getPrice());
        }

        cout << i << endl;

        cout << "Year: " << i
             << " - Gas Prices per Gallon" << endl;

        cout << "Highest price: $ " << getHighestPrice(price) << endl;

        cout << "Lowest price: $ " << getLowestPrice(price) << endl;

        cout << "Average price: $ " << getAveragePrice(price) << endl;

        cout << endl;

        // Create an ofstream object and open "Output.txt" in append mode
        ofstream outputFile("Output.txt", ios::app);

        // Check if the file is open and ready for writing
        if (outputFile.is_open()) {
            outputFile << "Year: " << i
                       << " - Gas Prices per Gallon" << endl;

            outputFile << "Highest price: $ " << getHighestPrice(price) << endl;
            outputFile << "Lowest price: $ " << getLowestPrice(price) << endl;
            outputFile << "Average price: $ " << getAveragePrice(price) << endl;
            outputFile << endl;

            // Close the file
            outputFile.close();
        }
        else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    return 0;
}

// This function only used for extracting data with format of DD-MM-YYYY:DATA
string getWord(string &s, string delim)
{
    // Var to store required value
    string temp;

    // Find position of delim
    int pos = s.find(delim);

    if (pos > 0)
    {
        temp += s.substr(0, pos);

        s.erase(0, pos);

        return temp;
    }
    else if(delim == ":")
    {
        // Erase delim at 0 index
        s.erase(0, 1);

        int length = s.length();

        for (int i = 0; i < length; i++)
        {
            temp += s.substr(0, 1);
            s.erase(0, 1);
        }

        return temp;
    }
    else
    {
        // Erase delim at 0 index
        s.erase(0, 1); // s =05-1993:1.068

        // Find new position of delim
        pos = s.find(delim);

        // if there is no "-" then find "::
        if (pos < 0)
        {
            pos = s.find(":");
        }

        temp += s.substr(0, pos);

        s.erase(0, pos);

        return temp;
    }
}

double getLowestPrice(auto d)
{
    return *min_element(d.begin(), d.end());
}

double getHighestPrice(auto d)
{
    return *max_element(d.begin(), d.end());
}

double getAveragePrice(auto d)
{
    double sum;
    int count = 0;

    for (auto i : d)
    {
        sum += i;
        count ++;
    }

    // Avoid division by zero if the container is empty
    if (count == 0) {
        return 0.0; // or handle this case appropriately
    }

    return sum / count;
}

