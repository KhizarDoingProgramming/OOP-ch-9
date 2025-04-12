/*--PROGRAM STATEMENT: Start with the COUNTEN2 program in this chapter. It can 
increment or decrement a counter, but only using prefix notation. Using 
inheritance, add the ability to use postfix notation for both incrementing and 
decrementing. (See Chapter 8 for a description of postfix notation.)
*/
#include <iostream>
using namespace std;

class Counter {
protected:
    unsigned int count;
public:
    Counter(unsigned int c = 0) : count(c) {}

    unsigned int get_count() const {
        return count;
    }

    Counter operator++() { // Prefix
        return Counter(++count);
    }

    Counter operator++(int) { // Postfix
        return Counter(count++);
    }
};

class CountDn : public Counter {
public:
    using Counter::Counter; // Inherit constructors

    CountDn operator--() { // Prefix
        return CountDn(--count);
    }

    CountDn operator--(int) { // Postfix
        return CountDn(count--);
    }
};

int main() {
    CountDn c1;         // Starts at 0
    CountDn c2(100);    // Starts at 100

    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();

    ++c1; ++c1; ++c1;
    cout << "\nc1 (after ++3) = " << c1.get_count();

    --c2; --c2;
    cout << "\nc2 (after --2) = " << c2.get_count();

    CountDn c3 = --c2;
    cout << "\nc3 (after c3 = --c2) = " << c3.get_count();

    c2--;
    cout << "\nc2 (after c2--) = " << c2.get_count();

    c3 = c2--;
    cout << "\nc2 (after c3 = c2--) = " << c2.get_count();
    cout << "\nc3 (after c3 = c2--) = " << c3.get_count();

    cout << endl;
    return 0;
}
