/*--PROGRAM STATEMENT: Start with the ARROVER3 program in Chapter 8. Keep 
the safearay class the same as in that program, and, using inheritance, derive 
the capability for the user to specify both the upper and lower bounds of the 
array in a constructor. This is similar to Exercise 9 in Chapter 8, except that 
inheritance is used to derive a new class (you can call it safehilo) instead of 
modifying the original class.
*/
#include <iostream>
using namespace std;

class SafeArray {
protected:
    static const int LIMIT = 100;
    int arr[LIMIT] = {0};

public:
    int& operator[](int index) {
        if (index < 0 || index >= LIMIT) {
            cout << "\nError: Index " << index << " out of bounds [0-" << LIMIT - 1 << "]\n";
            exit(1);
        }
        return arr[index];
    }
};

class SafeRangeArray : public SafeArray {
    int lower, upper;

public:
    SafeRangeArray(int l, int u) {
        if (u - l + 1 > LIMIT) {
            cout << "\nError: Range too large for array capacity.\n";
            exit(1);
        }
        lower = l;
        upper = u;
    }

    int& operator[](int index) {
        if (index < lower || index > upper) {
            cout << "\nError: Index " << index << " out of allowed range [" << lower << "-" << upper << "]\n";
            exit(1);
        }
        return SafeArray::operator[](index - lower); // Normalize index
    }
};

int main() {
    int low, high;
    cout << "Enter lower and upper bounds for array (max size 100): ";
    cin >> low >> high;

    SafeRangeArray sa(low, high);
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        int choice, index, value;
        cout << "\nEnter 1 to set value, 2 to get value: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter index and value: ";
            cin >> index >> value;
            sa[index] = value;
        } else {
            cout << "Enter index to retrieve value: ";
            cin >> index;
            cout << "Value at index " << index << " is " << sa[index] << endl;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> again;
    }

    return 0;
}
