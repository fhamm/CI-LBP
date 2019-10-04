#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include "lbp.h"

using namespace std;
using namespace cv;

int main (int argc, char **argv) {
    
    if (argc != 2) {
        cout << "Number of input arguments is invalid." << endl;
        return -1;
    }

    Mat image;

    // Read file
    image = imread (argv[1], CV_LOAD_IMAGE_COLOR);
    
    // Check if input is valid
    if (!image.data) {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    // Converts image to grayscale
    Mat grayImage;

    cvtColor (image, grayImage, COLOR_BGR2GRAY);
    
    // Create window for display
    namedWindow ("Output", WINDOW_AUTOSIZE);

    // Show image inside window
    imshow ("Output", grayImage);

    waitKey(0);

    return 0;
}
