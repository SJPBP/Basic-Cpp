// Prabhdeep Singh - Warehouse Inventory Program
// Keeps track of parts inventory across warehouse storage bins
// Created September 2023

#include <iostream>
using namespace std;

// Declaration of the InventoryBin structure
struct InventoryBin
{
    string description; // Item description
    int num; // Number of parts in a bin
};

void warehouseCatalog(int bin_Number, InventoryBin* bin);
void bin_Changes(char function, InventoryBin &bin);


int main() {
    // Constant for array size
    const int NUM_BINS = 10;


    // Array of InventoryBins initialized
    InventoryBin bins[NUM_BINS] =
            {
            {"Valve", 10},
            {"Bearing", 5},
            {"Bushing", 15},
            {"Coupling", 21},
            {"Flange", 7},
            {"Gear", 5},
            {"Gear Housing", 5},
            {"Vacuum Gripper", 25},
            {"Cable", 18},
            {"Rod", 12}
            };

    //! Using True in while is wrong
    //! Use bin = -1;
    //! while(bin != 0)
    // Loop through until user input Zero
    while (true)
    {

        warehouseCatalog(NUM_BINS, bins);

        cout << "\n\n";

        // Ask for bin number or quit
        int bin_number;
        cout << "Enter 0 to quit, or choose a bin number: ";
        cin >> bin_number;
        if (bin_number == 0)
        {
            break;
        }
        else if (bin_number < 0 || bin_number > NUM_BINS)
        {
            cout << "Invalid bin number. Please enter a number between 0 and " << NUM_BINS << ".\n";
            continue;
        }

        // Add or Remove part in bin
        char bin_process;
        cout << "Add or Remove Parts (A or R): ";
        cin >> bin_process;

        // Change bin items
        bin_Changes(bin_process,bins[bin_number - 1]);


        cout << "\n\n";
    }

    return 0;
}

// Function to output warehouse items
void warehouseCatalog(int bin_number, InventoryBin* bin)
{
    // Output bin
    cout << "Warehouse Inventory" << endl;

    // loop through to output bin content
    for (int i = 0; i < bin_number; i++)
    {
        cout << " Bin # "  << i + 1 << ", Part: " + bin[i].description + ", Quantity: " << bin[i].num << endl;
    };
}

// Function to change bin
void bin_Changes(char function, InventoryBin &bin)
{
    int temp = 0;

    while (true)
    {
        if (function == 'A' || function == 'a')
        {
            cout << "How many parts to add? ";
        }
        else if (function == 'R' || function == 'r')
        {
            cout << "How many parts to remove? ";
        }
        cin >> temp;

        // Get only positive input
        if (temp < 0)
        {
            cout << "Enter a positive input value!\n";
            continue;
        }

        if (function == 'A' || function == 'a')
        {
            // Check if adding temp to bin exceeds the 30-item limit
            if ((bin.num + temp) > 30)
            {
                cout << "You have reached the bin limit of 30 items.\n";
                continue;
            }
            else
            {
                bin.num += temp;
                break;
            }
        }
        else if (function == 'R' || function == 'r')
        {
            // Check if bin has enough items to remove
            if (temp > bin.num)
            {
                cout << "You are trying to remove more items than are in the bin.\n";
                continue;
            }
            else
            {
                bin.num -= temp;
                break;
            }
        }
    }
}
