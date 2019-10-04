#include <iostream>
#include <math.h>
#include <string>

using namespace std;

#ifndef LBP_CLASSES

class Binary {

    public:

        int length;
        string value;

        // Binary class constructor
        Binary (string number);

        // Return the decimal (base 10) value of the binary number
        int toDecimal (); 

    private:

        // ASCII to Integer
        int atoi (char c) {return (c - 48);}
};

#endif


