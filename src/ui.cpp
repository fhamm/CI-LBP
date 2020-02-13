#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "ui.h"

// Check if input arguments are valid
bool isInputValid (int argc, char **argv) {

    // Catch size error
    if (argc <= 2)
        return false;

    // Catch variables
    bool hasInput = false;
    bool hasOutput = false;
    bool hasTechnique = false;
    bool hasMaskSize = false;
    bool hasDirection = false;
    bool hasOutputWindow = false;
    
    int technique;
    int direction;

    // Read parameters
    for (int i = 0; i < argc; i++) {

        // OBLIGATORY PARAMETERS

        // Check input file parameter
        if (!strcmp(argv[i], "-i") && (i != argc - 1))
            hasInput = true;
        
        // Check output file parameter
        if (!strcmp(argv[i], "-o") && (i != argc - 1))
            hasOutput = true;

        // Check technique parameter
        if (!strcmp(argv[i], "-t") && (i != argc - 1)) {
            hasTechnique = true;
            technique = atoi(argv[i + 1]);
        }
            
        // Check mask size parameter
        if (!strcmp(argv[i], "-m") && (i != argc - 1))
            hasMaskSize = true;

        // CONDITIONAL PARAMETERS

        // Check CLBP direction parameter
        if (!strcmp(argv[i], "-d") && (i != argc - 1)) {
            hasDirection = true;
            direction = atoi(argv[i + 1]);
        }
        
        // Check output window flag
        if (!strcmp(argv[i], "-w") && (i != argc - 1))
            hasOutputWindow = true;
    }

    // Catch errors
    if (!hasInput || !hasTechnique || !hasMaskSize)
        return false;

    if (!hasOutput && !hasOutputWindow)
        return false;
    
    if ((technique != 0) && (technique != 1))
        return false;

    if ((technique == 1) && !hasDirection)
        return false;

    if ((direction != 0) && (direction != 1))
        return false;

    // Test ended, returns true
    return true;
}

// Gets input file name from arguments
std::string getInputFileName (int argc, char **argv) {

    for (int i = 0; i < argc; i++)
        if (!strcmp(argv[i], "-i"))
            return argv[i + 1];
    return "";
}

// Gets output file state from arguments
bool getOutputFileState (int argc, char **argv) {

    for (int i = 0; i < argc; i++)
        if (!strcmp(argv[i], "-o"))
            return true;
    return false;
}

// Gets output file name from arguments
std::string getOutputFileName (int argc, char **argv) {

    for (int i = 0; i < argc; i++)
        if (!strcmp(argv[i], "-o"))
            return argv[i + 1];
    return "";
}

// Gets technique type from arguments
int getTechnique (int argc, char **argv) {

    for (int i = 0; i < argc; i++)
        if (!strcmp(argv[i], "-t"))
            return atoi (argv[i + 1]);
    return -1;
}

// Gets technique type from arguments
int getMaskSize (int argc, char **argv) {

    for (int i = 0; i < argc; i++)
        if (!strcmp(argv[i], "-m"))
            return atoi (argv[i + 1]);
    return -1;
}

// Gets CLBP direction from arguments
int getDirection (int argc, char **argv) {

    for (int i = 0; i < argc; i++)
        if (!strcmp(argv[i], "-d"))
            return atoi (argv[i + 1]);
    return -1;
}

// Gets output window state from arguments
bool getOutputWindowState (int argc, char **argv) {

    for (int i = 0; i < argc; i++)
        if (!strcmp(argv[i], "-w"))
            return true;
    return false;
}

// Gets output window state from arguments
bool getHelpState (int argc, char **argv) {

    for (int i = 0; i < argc; i++)
        if (!strcmp(argv[i], "-h"))
            return true;
    return false;
}

// Print process information
void printInfo (int argc, char **argv) {

    // Get values
    bool outputFileState = getOutputFileState (argc, argv);
    bool outputWindowState = getOutputWindowState (argc, argv);

    std::string inputFileName = getInputFileName (argc, argv);
    std::string outputFileName = getOutputFileName (argc, argv);

    int technique = getTechnique (argc, argv);
    int maskSize = getMaskSize (argc, argv);
    int direction = getDirection (argc, argv);

    // Print header
    std::cout << "CiLBP - UFPR" << std::endl;

    // Print input information
    std::cout << "Input: " << "'" << inputFileName << "'" << std::endl;
    
    // Print output information
    if (outputFileState && outputWindowState)
        std::cout << "Output: " << "'" << outputFileName << "'" << " and Output Window" << std::endl;
    else if (outputFileState)
        std::cout << "Output: " << "'" << outputFileName << "'" << std::endl;
    else if (outputWindowState)
        std::cout << "Output: " << "Output Window" << std::endl;

    // Print technique information
    if (technique == 0)
        std::cout << "Technique: " << "Local Binary Pattern" << " with " << maskSize << "x" << maskSize << " pixel mask" << std::endl;
    else if (technique == 1) {      
        std::cout << "Technique: " << "Compound Local Binary Pattern" << " with " << maskSize << "x" << maskSize << " pixel mask and ";
        if (direction == 0)
            std::cout << "anti-clockwise rotation." << std::endl;
        else if (direction == 1)
            std::cout << "clockwise rotation." << std::endl;
    }

    // Print blank line
    std::cout << std::endl;
}
