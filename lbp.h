#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <math.h>
#include <string>

using namespace std;
using namespace cv;

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

void imageToGrayscale (Mat &image);
void applyLBP (Mat &image, int maskSize);

