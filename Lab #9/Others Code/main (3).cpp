// Owner is Nhien Dinh <nhien_dinh@mymail.rcbc.edu>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std; 

// Function to parse a line into date and price using ":" delimiter
pair<string, double> parseLine (const string& line) { 
    istringstream iss(line);
    string date;
    double price;

    getline(iss, date, ':');
    iss >> price;

    return make_pair(date, price);
}

int main() {
    // Input and Output files
    ifstream inputFile("GasPrices.txt");
    ofstream outputFile("output.txt");
    
    string line;
    
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Failed to open files" << endl;
        return 1;
    }

    
    // Using a map to group data by year
    map<int, vector<double>> yearPrices;

    while (getline(inputFile, line)) {
        auto data = parseLine(line);
        
        int year = stoi(data.first.substr(6, 4)); // Extract the year part
        
        yearPrices[year].push_back(data.second);
    }
    
    inputFile.close();
    
    // Iterate through each year, calculate statistics, and write to the output file
    for (const auto& entry : yearPrices) {
        int year = entry.first;
        
        const vector<double>& prices = entry.second;
        
        double minPrice = *min_element(prices.begin(), prices.end());
        double maxPrice = *max_element(prices.begin(), prices.end());
        double avgPrice = 0.0;
        
        // accumulate will calculate the sum of number 
        double avgPrice = accumulate(prices.begin(), prices.end(), 0.0) / prices.size();
        
        // Write the results to the output file
        outputFile << "\t\nYear " << year << "- Gas Prices per Gallon" << endl;
        outputFile << "  Highest Price: " << maxPrice << endl;
        outputFile << "  Lowest Price: " << minPrice << endl;
        outputFile << "  Average Price: " << avgPrice << endl;
    }
    
    outputFile.close();

    cout << "Data processed and written to output.txt." << endl;
    
    return 0;
}

