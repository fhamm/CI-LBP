#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

#include "lbp.h"

using namespace std;
using namespace cv;

// Binary class constructor
Binary::Binary (string number) {
    
    value = number;
    length = value.length();
}

// Returns the decimal (base 10) value of the binary number
int Binary::toDecimal() {
    
    int decimal = 0, i = 0;
    
    // Convert binary to decimal
    for (int p = length - 1; p >= 0; p--) {
        decimal = decimal + (atoi(value [p]) * pow(2, i));
        i++;
    }

    // Return decimal
    return decimal;
}

// Returns the ceil of the binary number
Binary Binary::getCeil () {
	
    string aux;

    // Calculate ceil
    for (int i=0; i < length; i++) {
        
        if (value [i] == '1')
            aux.append ("1");
    }

    for (int i = aux.length(); i < length; i++) {

        aux.append ("0");
    }

    // Return value
    Binary output (aux);

    return output;
}	

// Convert RGB image to Grayscale
void imageToGrayscale (Mat &image) {
    
    cvtColor (image, image, COLOR_BGR2GRAY);
}

// Get image mask diffrence average value
uchar getMaskDifferenceAverage (Mat &image, int maskSize, int x, int y) {
    
    ushort sum = 0;

    uchar centralPixel = image.at<uchar>(x + (maskSize / 2), y + (maskSize / 2));
    
    // Scroll over mask and sum it's difference values
    for (int i = x; i < (x + maskSize); i++)
        
        for (int j = y; j < (y + maskSize); j++)
         
            if (i != j)
                sum += (uchar) abs(image.at<uchar>(i, j) - centralPixel);

    // Calculate average
    uchar average = sum / ((maskSize * maskSize) - 1);

    // Returns average
    return average;
}

// Apply LBP technique
void applyLBP (Mat &image, int maskSize) {

    // Catch errors
    if (maskSize % 2 == 0)
        exit (EXIT_FAILURE);

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

                    uchar currentPixel = image.at<uchar>(i + x, j + y);
                    
                    // Ignore central pixel
                    if ((x != (maskSize / 2)) and (y != (maskSize / 2))) {

                            // Compare current pixel to central pixel
                            if (currentPixel >= centralPixel)
                                binaryString.append("1");
                            else
                                binaryString.append("0");
                    }
                }
            }
            
            // Create a binary number, calculate his ceil value and convert it to a decimal number. After, insert it into the array.
            Binary binaryNumber (binaryString);

            binaryNumber = binaryNumber.getCeil();

            auxImage.at<uchar>(i, j) = (uchar) binaryNumber.toDecimal();
        }
    }

    // Replace original image
    image = auxImage.clone();
}

// Apply Compound LBP technique
void applyCompoundLBP (Mat &image, int maskSize, int direction) {

    // Catch errors
    if (maskSize % 2 == 0)
        exit (EXIT_FAILURE);

    // Convert image to Grayscale
    imageToGrayscale (image);
    
    // FILTER
    
    // Output image
    Mat auxImage (image.rows, image.cols, CV_8UC1, Scalar(0, 0, 0));
    
    // Filter image
    for (int i = (maskSize / 2); i < image.rows; i++) {
        
        for (int j = (maskSize / 2); j < image.cols; j++) {

            uchar centralPixel = image.at<uchar>(i + (maskSize / 2), j + (maskSize / 2));

            // Calculate average
            uchar average = getMaskDifferenceAverage (image, maskSize, i, j);

            // Generate binary CLBP code 

            string binaryCLBP;

            // Scroll trough mask
            for (int x = 0; x < maskSize; x++) {
                
                for (int y = 0; y < maskSize; y++) {

                    uchar currentPixel = image.at<uchar>(i + x, j + y);
                    
                    // Ignore central pixel
                    if ((x != (maskSize / 2)) and (y != (maskSize / 2))) {

                            // Compare current pixel to central pixel
                            if (currentPixel >= centralPixel)
                                binaryCLBP.append("1");
                            else
                                binaryCLBP.append("0");

                            // Compare current pixel, central pixel and average
                            if (abs(currentPixel - centralPixel) > average)
                                binaryCLBP.append("1");
                            else
                                binaryCLBP.append("0");
                    }
                }
            } 

            string binaryString;

            // Apply CLBP technique in clockwise direction
            if (direction >= 0) {
            
                for (unsigned int p = 0; p < binaryCLBP.size(); p += 3)
                    binaryString += binaryCLBP.at(p) + binaryCLBP.at(p+1);
        
            }
            // Apply CLBP technique in counter-clockwise direction
            else {

                for (unsigned int p = 3; p < binaryCLBP.size(); p += 3)
                    binaryString += binaryCLBP.at(p) + binaryCLBP.at(p+1);
   
            }
            // Create a binary number, calculate his ceil value and convert it to a decimal number. After, insert it into the array.
            Binary binaryNumber (binaryString);

            // binaryNumber = binaryNumber.getCeil();

            auxImage.at<uchar>(i, j) = (uchar) binaryNumber.toDecimal();  
        }   
    }

    // Replace original image
    image = auxImage.clone();
}