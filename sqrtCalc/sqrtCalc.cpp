/*
Credit to hurubon on Discord for insight on my program.
This is revised according to their insight.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char command; // for persist

    do { // get num, check, calc, then repeat
        long double number;
        if (cin >> number) {
            cout << sqrt(number);
        }
        else {
            cout << "Invalid input.\n";
            continue;
        }
        // repeat
        cin >> command;
    } while (command == 'y'); // end do,while
} // end main