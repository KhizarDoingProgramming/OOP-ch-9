/*--PROGRAM STATEMENT: Derive a class called employee2 from the employee 
class in the EMPLOY program in this chapter. This new class should add a type 
double data item called compensation, and also an enum type called period to 
indicate whether the employee is paid hourly, weekly, or monthly. For simplicity 
you can change the manager, scientist, and laborer classes so they are derived 
from employee2 instead of employee. However, note that in many circumstances it 
might be more in the spirit of OOP to create a separate base class called 
compensation and three new classes manager2, scientist2, and laborer2, and use 
multiple inheritance to derive these three classes from the original manager, 
scientist, and laborer classes and from compensation. This way none of the 
original classes needs to be modified.
*/
#include <iostream>
#include <string>
using namespace std;

enum PayPeriod { HOURLY, WEEKLY, MONTHLY };

class Compensation {
protected:
    double amount{};
    PayPeriod period{};

public:
    void getData() {
        char ch;
        cout << "  Enter compensation: ";
        cin >> amount;
        cout << "  Enter pay period (h = hourly, w = weekly, m = monthly): ";
        cin >> ch;

        switch (ch) {
            case 'h': period = HOURLY; break;
            case 'w': period = WEEKLY; break;
            case 'm': period = MONTHLY; break;
            default: period = HOURLY; break;
        }
    }

    void putData() const {
        cout << "\n  Compensation   : $" << amount;
        cout << "\n  Pay period     : ";
        switch (period) {
            case HOURLY: cout << "Hourly"; break;
            case WEEKLY: cout << "Weekly"; break;
            case MONTHLY: cout << "Monthly"; break;
        }
    }
};

class Employee : public Compensation {
protected:
    string name;
    unsigned long ID{};

public:
    virtual void getData() {
        cin.ignore();
        cout << "\n  Enter name: ";
        getline(cin, name);
        cout << "  Enter ID: ";
        cin >> ID;
        Compensation::getData();
    }

    virtual void putData() const {
        cout << "\n  Name           : " << name;
        cout << "\n  ID             : " << ID;
        Compensation::putData();
    }

    virtual ~Employee() = default;  // Virtual destructor for base class
};

class Manager : public Employee {
    string title;
    double dues{};

public:
    void getData() override {
        Employee::getData();
        cout << "  Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "  Enter golf club dues: ";
        cin >> dues;
    }

    void putData() const override {
        Employee::putData();
        cout << "\n  Title          : " << title;
        cout << "\n  Golf club dues : $" << dues;
    }
};

class Scientist : public Employee {
    int publications{};

public:
    void getData() override {
        Employee::getData();
        cout << "  Enter number of publications: ";
        cin >> publications;
    }

    void putData() const override {
        Employee::putData();
        cout << "\n  Publications   : " << publications;
    }
};

class Laborer : public Employee {
    // Inherits everything from Employee directly
};

int main() {
    Manager m1, m2;
    Scientist s1;
    Laborer l1;

    cout << "\nEnter data for Manager 1:";
    m1.getData();
    cout << "\nEnter data for Manager 2:";
    m2.getData();
    cout << "\nEnter data for Scientist 1:";
    s1.getData();
    cout << "\nEnter data for Laborer 1:";
    l1.getData();

    cout << "\n\n--- Displaying Employee Data ---";
    cout << "\nManager 1:"; m1.putData();
    cout << "\n\nManager 2:"; m2.putData();
    cout << "\n\nScientist 1:"; s1.putData();
    cout << "\n\nLaborer 1:"; l1.putData();

    cout << endl;
    return 0;
}
