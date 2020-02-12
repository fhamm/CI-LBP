#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;
using namespace cv;

#ifndef LBP_CLASSES

class Binary {

    public:

        int length;
        string value;

        // Binary class constructor
        Binary (string number);

        // Returns the decimal (base 10) value of the binary number
        int toDecimal (); 

        // Returns the ceil of the binary number
        Binary getCeil ();

    private:

        // ASCII to Integer
        int atoi (char c) {return (c - 48);}
};

#endif

// Convert RGB image to Grayscale
void imageToGrayscale (Mat &image);

// Get image mask diffrence average value
uchar getMaskDifferenceAverage (Mat &image, int maskSize, uchar x, uchar y);

// Apply LBP technique
void applyLBP (Mat &image, int maskSize);

// Apply Compound LBP technique
void applyCompoundLBP (Mat &image, int maskSize, int direction);