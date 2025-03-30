#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    // Var used in the program
    fstream binary_file;
    
    stack<int> myStack;
    
    string Binary;
    
    binary_file.open("binary.txt");

    // Check file successfully opened
    if (binary_file.fail()) {
        cout << "ERROR: File wasn't successfully opened!";
        exit(1);
    }

    getline(binary_file, Binary);
    
    // Check on bit number 
    int bitCount = 0;

    // Count how many times '1' is present in the string
    int neg_count = 0;

    for(int i : Binary)
    {
        // Reset for new Byte
        if (bitCount == 8)
        {
            bitCount = 0;
            neg_count = 0;
        }

        myStack.push(i);

        if (i == '1')
        {
            neg_count ++;
        }

        bitCount ++;

        if (bitCount == 8 &&  !(neg_count % 2 == 0))
        {
            for (int x = 0; x < 8; x++)
            {

                myStack.pop();
                bitCount--;
            }

            cout << "“negative acknowledge # " << neg_count << endl;
        }
    }
    
    binary_file.close();

    Binary = "";
    
    bitCount = 0;
    
    cout << "The size of stack is " <<  myStack.size() << endl;
    
    while (!myStack.empty()) 
    {
        // Inner loop for processing each 8-bit segment
        for (int i = 0; i < 8 && !myStack.empty(); ++i)
        {
            if (i != 0)  // Skip the first bit (parity bit)
            {
                cout << char(myStack.top()); // Print the bit

                bitCount++;

                if (bitCount % 7 == 0) cout << endl; // New line after every 7 bits

            }

            myStack.pop();
        }
    }


    return 0;
}
