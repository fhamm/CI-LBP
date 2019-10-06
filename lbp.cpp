#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <math.h>
#include <string>
#include "lbp.h"

using namespace std;
using namespace cv;

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

// Convert RGB image to Grayscale
void imageToGrayscale (Mat &image) {
    
    cvtColor (image, image, COLOR_BGR2GRAY);
}

// Apply LBP filter
void applyLBP (Mat &image, int maskSize) {

    // Convert image to Grayscale
    imageToGrayscale (image);
    
    // FILTER
    
    // Output image
    Mat auxImage (image.rows, image.cols, CV_8UC1, Scalar(0, 0, 0));
    
    // Filter image
    for (int i = (maskSize / 2); i < image.rows; i++) {
        
        for (int j = (maskSize / 2); j < image.cols; j++) {
            
            uchar centralPixel = image.at<uchar>(i + (maskSize / 2), j + (maskSize / 2));
            string binaryString;

            for (int x = 0; x < maskSize; x++) {
                
                for (int y = 0; y < maskSize; y++) {
                    
                    if ((x != (maskSize / 2)) and (y != (maskSize / 2))) {

                            if (image.at<uchar>(i + x, j + y) >= centralPixel)
                                binaryString.append("1");
                            else
                                binaryString.append("0");
                    }
                }
            }
            
            Binary binaryNumber (binaryString);

            auxImage.at<uchar>(i, j) = (uchar) binaryNumber.toDecimal();
        }
    }
    
    image = auxImage.clone();
}
