#include <iostream>
#include <math.h>
#include <string>

using namespace std;

string getInput() {
    // get user input
    cout << "Enter a number to take the square root of:" << endl;
    string rootNumberStr;
    cin >> rootNumberStr;
    
    // check if input is int
    for (int i = 0; i < rootNumberStr.length(); i++) {
        // repeat until user inputs valid number
        do {
            cout << "Enter a number to take the square root of:" << endl;
            cin >> rootNumberStr;
        } while (isdigit(rootNumberStr[i]) != true);

    } // end for

    return rootNumberStr;

} // end getInput


int main() {
    char cont = 'y';
    
    while (cont != 'n') {
        // get rootNumberStr and persist
        string rootNumberStr = getInput();
        // convert and calculate sqrt
        int rootNumber = stoi(rootNumberStr);
        long double squareRoot = sqrt(rootNumber);
        cout << "Principal root of " << rootNumberStr << " is:\n" << squareRoot << endl;
        // check if continue?
        cout << "Continue? [y/n]\n";
        cin >> cont;
    }

} // end main