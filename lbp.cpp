#include <iostream>
#include <math.h>
#include <string>
#include "lbp.h"

// Binary class constructor
Binary::Binary (string number) {
    
    value = number;
    length = value.length();
}

// Return the decimal (base 10) value of the binary number
int Binary::toDecimal() {
    
    int decimal = 0, i = 0;
    
    for (int p = length - 1; p >= 0; p--) {
        decimal = decimal + (atoi(value [p]) * pow(2, i));
        i++;
    }

    return decimal;
}
