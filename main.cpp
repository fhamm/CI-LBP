#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>
#include "lbp.h"

using namespace std;
using namespace cv;

int main (int argc, char **argv) {
    
    // Check if number of arguments is valid
    if (argc != 2) {
        cout << "Number of input arguments is invalid." << endl;
        return -1;
    }
    
    // Declare image container and read file
    Mat image = imread (argv[1], CV_LOAD_IMAGE_COLOR);
    
    // Check if input is valid
    if (!image.data) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Apply filter to image
    applyLBP (image, 3);
    
    // OUTPUT

    // Create window for display
    namedWindow ("Output", WINDOW_AUTOSIZE);

    // Show image inside window
    imshow ("Output", image);
    
    waitKey(0);

    return 0;
}
