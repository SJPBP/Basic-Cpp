#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

int main() {
    // Variable used
    fstream datafile;
    string fileName, line;
    int lineNumber = 0;

    // Get file name frmo User
    cout << "Enter the file name: ";
    getline(cin, fileName);

    // Open the file
    datafile.open(fileName, ios::in);

    // Check file successfully opened
    if (datafile.fail())
    {
        cout << "ERROR: File wasn't successfully opened!";
        exit(1);
    }

    // Getting content from file
    getline(datafile, line);

    // Keep looping until theres nothing in file
    while (datafile)
    {
        lineNumber++;
        cout << setw(3) << lineNumber << ":" << line << endl;

        if (lineNumber % 24 == 0)
        {
            cout << setw(8) << "" << "Press Enter to continue...";
            cin.get();
            datafile.get();
        }


        getline(datafile, line);

    }
    datafile.close();
    return 0;
}
