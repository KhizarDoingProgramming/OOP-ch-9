/*--PROGR STATEMENT: Operators in some computer languages, such as Visual 
Basic, allow you to select parts of an existing string and assign them to other 
strings. (The Standard C++ string class offers a different approach.) Using 
inheritance, add this capability to the Pstring class of Exercise 2. In the 
derived class, Pstring2, incorporate three new functions: left(), mid(), and 
right(). 
	s2.left(s1, n)    // s2 is assigned the leftmost n characters 
	                  //    from s1 
	s2.mid(s1, s, n)  // s2 is assigned the middle n characters 
	                  //    from s1, starting at character number s 
	                  //    (leftmost character is 0) 
	s2.right(s1, n)   // s2 is assigned the rightmost n characters 
	                  //    from s1 
You can use for loops to copy the appropriate parts of s1, character by 
character, to a temporary Pstring2 object, which is then returned. For extra 
credit, have these functions return by reference, so they can be used on the 
left side of the equal sign to change parts of an existing string.
*/
//NOTE 1: Return by reference to use on the left side of the equal sign task not completed.
#include <iostream>
#include <cstring>
using namespace std;

class String {
protected:
    static const int SZ = 80;
    char str[SZ];
public:
    String() { str[0] = '\0'; }
    String(const char* s) { strncpy(str, s, SZ - 1); str[SZ - 1] = '\0'; }

    void display() const { cout << str; }

    operator const char*() const { return str; }
};

class Pstring : public String {
public:
    Pstring() : String() {}
    Pstring(const char* s) {
        strncpy(str, s, SZ - 1);
        str[SZ - 1] = '\0';
    }
};

class Pstring2 : public Pstring {
public:
    Pstring2() : Pstring() {}
    Pstring2(const char* s) : Pstring(s) {}

    void left(const Pstring2& src, int n) {
        strncpy(str, src.str, n);
        str[n] = '\0';
    }

    void mid(const Pstring2& src, int start, int len) {
        int srcLen = strlen(src.str);
        if (start >= srcLen) {
            str[0] = '\0';
            return;
        }
        strncpy(str, src.str + start, len);
        str[len] = '\0';
    }

    void right(const Pstring2& src, int n) {
        int srcLen = strlen(src.str);
        if (n > srcLen) n = srcLen;
        strncpy(str, src.str + srcLen - n, n);
        str[n] = '\0';
    }
};

int main() {
    Pstring2 s1("Joyeux Noel!");
    cout << "s1 = ";
    s1.display();

    cout << endl;
    
    Pstring2 s3;
    
    s3.left(s1, 8);
    s3.display(); // Joyeux 

    cout << endl;

    s3.mid(s1, 4, 4);
    s3.display(); // eux 

    cout << endl;

    s3.right(s1, 7);
    s3.display(); // uel!

    cout << endl;
    return 0;
}
