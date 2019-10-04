#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Binary {

    public:

        int length;
        string value;

        // Constructor
        Binary (string number) {
            
            value = number;
            length = value.length();
        }

        // Return the decimal (base 10) value of the binary number
        int toDecimal () {

            int decimal = 0, i = 0;

            for (int p = length - 1; p >= 0; p--) {

                decimal = decimal + (atoi(value [p]) * pow(2, i));
                i++;
            }

            return decimal;
        }

    private:

        // ASCII to Integer
        int atoi (char c) {

            return (c - 48);
        }
};

int main () {

    Binary n1("10010100");

    cout << n1.toDecimal() << endl;
}