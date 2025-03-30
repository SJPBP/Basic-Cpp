#include <iostream>
#include <fstream>
#include "DivSales.h"

using namespace std;



int main() {
    DivSales division[6];
    int userDiv = 7;
    fstream  inFiile;

    // Open the file
    inFiile.open("SalesFile.txt", ios::in);

    // Check file successfully opened
    if (inFiile.fail())
    {
        cout << "ERROR: File wasn't successfully opened!";
        exit(1);
    }

    for (int div = 0; div < 6; div++)
    {
        for (int qrt = 0; qrt < 4; qrt++)
        {
            inFiile >> division[div].qtrs[qrt];
            division[div].setDivSales(division[div].qtrs[qrt]);
        }
        division[div].setCorpSales(division[div].getDivSales());
    }

    cout << "Enter a division (1-6), or 0 to quit: ";
    cin >> userDiv;
    cout << endl;

    while (userDiv != 0)
    {
        for (int qrt = 0; qrt < 4; qrt++) {
            cout << "\tDivision #" << userDiv << "\tQuarter 1 seles: $";
            cout << division[userDiv - 1].qtrs[qrt] << endl;
        }
        cout << endl;

        cout << "\tDivision #" << userDiv << " total Sales are: $";
        cout << division[userDiv - 1].getDivSales() << endl;

        cout << endl;

        cout << "Enter a division (1-6), or 0 to quit: ";
        cin >> userDiv;

        cout << endl;
    }

    cout << "Total corporate sales: $" << division->getCorpSales();
    cout << endl;

    inFiile.close();
    return 0;
}

/*
Engineer Name: Prabhdeep Singh

Project/program description: The program reads sales data for six divisions, each having sales data for four quarters, from the "SalesFile.txt" file. The program then prompts the user to input a division number (1-6) to display sales for each quarter and the total sales for that division. The user can continue to input division numbers or enter 0 to quit. At the end, the program displays the total corporate sales

Test Case #1: Test reading sales data from the file
Expected Test Results: The program should successfully read 24 sales data entries from the file and update the 6 DivSales objects with this data
Actual Test Results: The program successfully read the sales data and updated the DivSales objects as expected

Test Case #2: Display sales for a specific division
Expected Test Results: The program should display sales for each quarter and the total sales for the division input by the user. The sales should match the data from the file
Actual Test Results: The program correctly displayed the sales for each quarter and the total sales for the input division, matching the data from the file

Test Case #3: The total corporate sales should be the sum of all sales data entries from the file
Expected Test Results: The total corporate sales should be the sum of all sales data entries from the file
Actual Test Results: The program correctly calculated and displayed the total corporate sales, matching the sum of the sales data from the file

Test Case #4: Test the loop and exit mechanism
Expected Test Results: The program should immediately display the total corporate sales and exit without further prompts when the user inputs 0
Actual Test Results:The program displayed the total corporate sales and exited as expected upon user input of 0
*/
