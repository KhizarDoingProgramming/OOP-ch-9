/*--PROGRAM STATEMENT: Start with the publication, book, and tape classes 
of Exercise 1. Add a base class sales that holds an array of three floats so 
that it can record the dollar sales of a particular publication for the last 
three months. Include a getdata() function to get three sales amounts from the 
user, and a putdata() function to display the sales figures. Alter the book 
and tape classes so they are derived from both publication and sales. An object 
of class book or tape should input and output sales data along with its other 
data. Write a main() function to create a book object and a tape object and 
exercise their input/output capabilities.
*/
#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0f) {}
    Publication(string t, float p) : title(t), price(p) {}

    void getData() {
        cin.ignore(); // clear buffer
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void putData() const {
        cout << "Title: " << title << "\nPrice: $" << price;
    }
};

class Sales {
protected:
    float salesMonth[3]{};

public:
    Sales() = default;
    Sales(float arr[3]) {
        for (int i = 0; i < 3; ++i)
            salesMonth[i] = arr[i];
    }

    void getData() {
        for (int i = 0; i < 3; ++i) {
            cout << "Enter sales for month " << i + 1 << ": ";
            cin >> salesMonth[i];
        }
    }

    void putData() const {
        for (int i = 0; i < 3; ++i)
            cout << "\nMonth " << i + 1 << " sales: $" << salesMonth[i];
    }
};

class Book : public Publication, public Sales {
    int pageCount;

public:
    Book() : Publication(), Sales(), pageCount(0) {}
    Book(string t, float p, int pc, float sm[3]) : Publication(t, p), Sales(sm), pageCount(pc) {}

    void getData() {
        cout << "\nEnter Book Details:\n";
        Publication::getData();
        cout << "Enter number of pages: ";
        cin >> pageCount;
        Sales::getData();
    }

    void putData() const {
        cout << "\nBook Details:\n";
        Publication::putData();
        cout << "\nPage count: " << pageCount;
        Sales::putData();
    }
};

class Tape : public Publication, public Sales {
    float minutes;

public:
    Tape() : Publication(), Sales(), minutes(0.0f) {}
    Tape(string t, float p, float m, float sm[3]) : Publication(t, p), Sales(sm), minutes(m) {}

    void getData() {
        cout << "\nEnter Tape Details:\n";
        Publication::getData();
        cout << "Enter duration in minutes: ";
        cin >> minutes;
        Sales::getData();
    }

    void putData() const {
        cout << "\nTape Details:\n";
        Publication::putData();
        cout << "\nDuration: " << minutes << " minutes";
        Sales::putData();
    }
};

int main() {
    float bookSales[] = {2 * 56.54f, 3 * 56.54f, 5 * 56.54f};
    float tapeSales[] = {2 * 50.45f, 3 * 50.45f, 5 * 50.45f};

    Book b1("Inheritance", 56.54f, 50, bookSales);
    Tape t1("Generalisation", 50.45f, 16.54f, tapeSales);

    b1.putData();
    t1.putData();

    b1.getData();
    t1.getData();

    b1.putData();
    t1.putData();

    return 0;
}
