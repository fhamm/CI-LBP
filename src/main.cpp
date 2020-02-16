#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>

#ifndef HEADERS
#include "lbp.h"
#include "ui.h"
#endif

using namespace std;
using namespace cv;

int main (int argc, char **argv) {

    // INPUT
    
    // Check if input arguments are valid
    if (!isInputValid(argc, argv)) {
        cerr << "ERROR: invalid input arguments..." << endl;
        return -1;
    }

    // Check if help was called
    if (getHelpState) {
        printHelp ();
        return 0;
    }

    printInfo (argc, argv);
    
    // Declare image container and read the input file
    Mat image = imread (getInputFileName(argc, argv), CV_LOAD_IMAGE_COLOR);
    
    // Check if input is valid
    if (!image.data) {
        cerr << "ERROR: could not open or find the input image file..." << endl;
        return -1;
    }

    cout << "Creating modified image..." << endl;

    // APPLY TECHNIQUES

    if (getTechnique(argc, argv) == 0) 
        applyLBP (image, getMaskSize(argc, argv));
    else if (getTechnique(argc, argv) == 1)
        applyCompoundLBP (image, getMaskSize(argc, argv), getDirection(argc, argv));

    cout << "Image created. Preparing output..." << endl;
    
    // OUTPUT

    // If output file is defined, write the file
    if (getOutputFileState(argc, argv)) {

        cout << "Writing output image file..." << endl;

        imwrite(getOutputFileName(argc, argv), image);

        cout << "Output image file created" << endl;
    }

    // If flag is marked, show output window
    if (getOutputWindowState(argc, argv)) {

        cout << "Creating output window..." << endl;

        namedWindow ("Output", WINDOW_AUTOSIZE);
        imshow ("Output", image);

        cout << "Output window created. Press any key to exit." << endl;

        waitKey (0);

        cout << "Output window closed." << endl;
    }

    cout << "Success." << endl;

    // Return success
    return 0;
}
