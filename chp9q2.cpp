/*--PROGRAM STATEMENT: Recall the STRCONV example from Chapter 8. The String class 
in this example has a flaw: It does not protect itself if its objects are 
initialized to have too many characters. (The SZ constant has the value 80.) For 
example, the definition 
	String s = “This string will surely exceed the width of the “
	“screen, which is what the SZ constant represents.”;
will cause the str array in s to overflow, with unpredictable consequences, 
such as crashing the system. 
With String as a base class, derive a class Pstring (for “protected string”) 
that prevents buffer overflow when too long a string constant is used in a 
definition. A new constructor in the derived class should copy only  SZ–1 
characters into str if the string constant is longer, but copy the entire 
constant if it’s shorter. Write a main() program to test different lengths of 
strings.
*/
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
        if (strlen(s) < SZ)
            strncpy(str, s, SZ - 1);
        else
            strncpy(str, s, SZ - 1);

        str[SZ - 1] = '\0';
    }
};

int main() {
    Pstring s1;
    const char* xstr = "Mango Apple!";
    s1 = xstr;
    cout << "s1 = "; s1.display();

    Pstring s2 = "Mustafa Khizar!";
    cout << "\ns2 = " << (const char*)(s2);

    Pstring s = "This string will surely exceed the width of the screen, which is what the SZ constant represents.";
    cout << "\n\nExpected: This string will surely exceed the width of the screen, which is what the SZ constant represents.";
    cout << "\nActual  : "; s.display();

    cout << endl;
    return 0;
}
