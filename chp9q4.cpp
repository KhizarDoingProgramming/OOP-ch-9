/*--PROGRAM STATEMENT: Assume that the publisher in Exercises 1 and 3 
decides to add a third way to distribute books: on computer disk, for those 
who like to do their reading on their laptop. Add a disk class that, like book 
and tape, is derived from publication. The disk class should incorporate the 
same member functions as the other classes. The data item unique to this class 
is the disk type: either CD or DVD. You can use an enum type to store this item. 
The user could select the appropriate type by typing c or d.
*/
#include <iostream>
#include <string>
using namespace std;

enum DiskType { CD, DVD };

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0f) {}
    Publication(string t, float p) : title(t), price(p) {}

    void getData() {
        cin.ignore();
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
    float sales[3]{};

public:
    Sales() = default;
    Sales(float arr[3]) {
        for (int i = 0; i < 3; ++i)
            sales[i] = arr[i];
    }

    void getData() {
        for (int i = 0; i < 3; ++i) {
            cout << "Enter sales for month " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    void putData() const {
        for (int i = 0; i < 3; ++i)
            cout << "\nMonth " << i + 1 << " sales: $" << sales[i];
    }
};

class Book : public Publication, public Sales {
    int pageCount;

public:
    Book() : Publication(), Sales(), pageCount(0) {}
    Book(string t, float p, int pc, float s[3]) : Publication(t, p), Sales(s), pageCount(pc) {}

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
        cout << "\nPages: " << pageCount;
        Sales::putData();
    }
};

class Tape : public Publication, public Sales {
    float minutes;

public:
    Tape() : Publication(), Sales(), minutes(0.0f) {}
    Tape(string t, float p, float m, float s[3]) : Publication(t, p), Sales(s), minutes(m) {}

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

class Disk : public Publication, public Sales {
    DiskType type;

public:
    Disk() : Publication(), Sales(), type(CD) {}
    Disk(string t, float p, DiskType d, float s[3]) : Publication(t, p), Sales(s), type(d) {}

    void getData() {
        cout << "\nEnter Disk Details:\n";
        Publication::getData();
        char choice;
        cout << "Enter disk type (c for CD / d for DVD): ";
        cin >> choice;
        type = (choice == 'd') ? DVD : CD;
        Sales::getData();
    }

    void putData() const {
        cout << "\nDisk Details:\n";
        Publication::putData();
        cout << "\nType: " << (type == CD ? "CD" : "DVD");
        Sales::putData();
    }
};

int main() {
    float bookSales[] = {2 * 56.54f, 3 * 56.54f, 5 * 56.54f};
    float tapeSales[] = {2 * 50.45f, 3 * 50.45f, 5 * 50.45f};

    Book b1("Inheritance", 56.54f, 50, bookSales);
    Tape t1("Generalisation", 50.45f, 16.54f, tapeSales);
    Disk d1("Specialisation", 50.45f, CD, tapeSales);

    b1.putData();
    t1.putData();
    d1.putData();

    b1.getData();
    t1.getData();
    d1.getData();

    b1.putData();
    t1.putData();
    d1.putData();

    return 0;
}
