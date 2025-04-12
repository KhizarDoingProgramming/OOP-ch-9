/*--PROGRAM STATEMENT: Imagine a publishing company that markets both book 
and audiocassette versions of its works. Create a class publication that stores 
the title (a string) and price (type float) of a publication. From this class 
derive two classes: book, which adds a page count (type int), and tape, which 
adds a playing time in minutes (type float). Each of these three classes should 
have a getdata() function to get its data from the user at the keyboard, and a 
putdata() function to display its data. 
Write a main() program to test the book and tape classes by creating instances 
of them, asking the user to fill in data with getdata(), and then displaying 
the data with putdata().
*/

#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}
    Publication(string t, float p) : title(t), price(p) {}

    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void putData() const {
        cout << "Title: " << title << "\nPrice: " << price;
    }
};

class Book : public Publication {
    int pageCount;

public:
    Book() : Publication(), pageCount(0) {}
    Book(string t, float p, int pc) : Publication(t, p), pageCount(pc) {}

    void getData() {
        cout << "\nEnter Book Details:\n";
        Publication::getData();
        cout << "Enter number of pages: ";
        cin >> pageCount;
    }

    void putData() const {
        cout << "\nBook Details:\n";
        Publication::putData();
        cout << "\nPages: " << pageCount;
    }
};

class Tape : public Publication {
    float minutes;

public:
    Tape() : Publication(), minutes(0.0) {}
    Tape(string t, float p, float m) : Publication(t, p), minutes(m) {}

    void getData() {
        cout << "\nEnter Tape Details:\n";
        Publication::getData();
        cout << "Enter duration (in minutes): ";
        cin >> minutes;
    }

    void putData() const {
        cout << "\nTape Details:\n";
        Publication::putData();
        cout << "\nDuration: " << minutes << " minutes";
    }
};

int main() {
    Book b1("Inheritance", 56.54, 50);
    Tape t1("Generalisation", 50.45, 16.54);

    b1.putData();
    t1.putData();

    b1.getData();
    t1.getData();

    b1.putData();
    t1.putData();

    return 0;
}
