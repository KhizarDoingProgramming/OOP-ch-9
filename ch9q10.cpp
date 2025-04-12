/*--PROGRAM STATEMENT: There is only one kind of manager in the EMPMULT 
program in this chapter. Any serious company has executives as well as managers. 
From the manager class derive a class called executive. (We’ll assume an 
executive is a high-end kind of manager). The additional data in the executive 
class will be the size of the employee’s yearly bonus and the number of shares 
of company stock held in his or her stock-option plan. Add the appropriate 
member functions so these data items can be input and displayed along with the 
other manager data.
*/	
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int empID;

public:
    void getData() {
        cout << "Enter employee name: ";
        getline(cin, name);
        cout << "Enter employee ID: ";
        cin >> empID;
        cin.ignore(); // clear buffer for next getline
    }

    void putData() const {
        cout << "Name: " << name << "\nID: " << empID;
    }
};

class Manager : public Employee {
protected:
    string department;
    float salary;

public:
    void getData() {
        Employee::getData();
        cout << "Enter department: ";
        getline(cin, department);
        cout << "Enter salary: ";
        cin >> salary;
        cin.ignore();
    }

    void putData() const {
        Employee::putData();
        cout << "\nDepartment: " << department
             << "\nSalary: $" << salary;
    }
};


class Executive : public Manager {
private:
    float bonus;
    int stock;

public:
    void getData() {
        Manager::getData();
        cout << "Enter yearly bonus: ";
        cin >> bonus;
        cout << "Enter number of company shares: ";
        cin >> stock;
        cin.ignore();
    }

    void putData() const {
        Manager::putData();
        cout << "\nYearly Bonus: $" << bonus
             << "\nStock Shares: " << stock;
    }
};

int main() {
    Executive exec;

    cout << "Enter executive details:\n";
    exec.getData();

    cout << "\nExecutive Information:\n";
    exec.putData();

    return 0;
}
