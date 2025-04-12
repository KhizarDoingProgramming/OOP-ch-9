/*--PROGRAM STATEMENT: Start with the publication, book, and tape classes 
of Exercise 1. Suppose you want to add the date of publication for both books 
and tapes. From the publication class, derive a new class called publication2 
that includes this member data. Then change book and tape so they are derived 
from publication2 instead of publication. Make all the necessary changes in 
member functions so the user can input and output dates along with the other 
data. For the dates, you can use the date class from Exercise 5 in Chapter 6, 
which stores a date as three  ints, for month, day, and year.
*/
#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication(string t = "", float p = 0.0f) : title(t), price(p) {}

    virtual void getData() {
        cin.ignore(); // clear buffer before getline
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putData() const {
        cout << "Title: " << title << "\nPrice: " << price;
    }
};

class Date {
private:
    int day, month, year;

public:
    Date(int d = 1, int m = 1, int y = 1920) : day(d), month(m), year(y) {}

    void getDate() {
        char sep;
        cin >> day >> sep >> month >> sep >> year;
    }

    void showDate() const {
        cout << day << '/' << month << '/' << year;
    }
};

class Publication2 : public Publication {
protected:
    Date pubDate;

public:
    Publication2(string t = "", float p = 0.0f, Date d = Date()) 
        : Publication(t, p), pubDate(d) {}

    void getData() override {
        Publication::getData();
        cout << "Enter date (dd/mm/yyyy): ";
        pubDate.getDate();
    }

    void putData() const override {
        Publication::putData();
        cout << "\nDate: ";
        pubDate.showDate();
    }
};

class Book : public Publication2 {
private:
    int pageCount;

public:
    Book(string t = "", float p = 0.0f, Date d = Date(), int pc = 0)
        : Publication2(t, p, d), pageCount(pc) {}

    void getData() override {
        cout << "Book:\n";
        Publication2::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putData() const override {
        cout << "Book:\n";
        Publication2::putData();
        cout << "\nPages: " << pageCount;
    }
};

class Tape : public Publication2 {
private:
    float minutes;

public:
    Tape(string t = "", float p = 0.0f, Date d = Date(), float m = 0.0f)
        : Publication2(t, p, d), minutes(m) {}

    void getData() override {
        cout << "Tape:\n";
        Publication2::getData();
        cout << "Enter duration (minutes): ";
        cin >> minutes;
    }

    void putData() const override {
        cout << "Tape:\n";
        Publication2::putData();
        cout << "\nDuration: " << minutes << " minutes";
    }
};

int main() {
    Book b1("Inheritance", 56.54f, Date(23, 11, 2012), 50);
    Tape t1("Generalisation", 50.45f, Date(10, 9, 1996), 16.54f);

    b1.putData();
    cout << "\n\n";
    t1.putData();

    cout << "\n\nEnter data for a new book:\n";
    b1.getData();

    cout << "\nEnter data for a new tape:\n";
    t1.getData();

    cout << "\n\nUpdated Details:\n";
    b1.putData();
    cout << "\n\n";
    t1.putData();

    return 0;
}
