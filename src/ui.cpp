#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "ui.h"

using namespace std;

// OBS: The C 'strcmp' function returns inverted values.

// Check if input arguments are valid
bool isInputValid (int argc, char **argv) {

    // Catch size error
    if (argc <= 1)
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
    for (int i = 1; i < argc; i++) {

        // Check if help was called
        if (!strcmp(argv[i], "-h"))
            return true;

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
string getInputFileName (int argc, char **argv) {

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
string getOutputFileName (int argc, char **argv) {

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

    string inputFileName = getInputFileName (argc, argv);
    string outputFileName = getOutputFileName (argc, argv);

    int technique = getTechnique (argc, argv);
    int maskSize = getMaskSize (argc, argv);
    int direction = getDirection (argc, argv);

    // Print header
    cout << "CiLBP - UFPR" << endl;

    // Print input information
    cout << "Input: " << "'" << inputFileName << "'" << endl;
    
    // Print output information
    if (outputFileState && outputWindowState)
        cout << "Output: " << "'" << outputFileName << "'" << " and Output Window" << endl;
    else if (outputFileState)
        cout << "Output: " << "'" << outputFileName << "'" << endl;
    else if (outputWindowState)
        cout << "Output: " << "Output Window" << endl;

    // Print technique information
    if (technique == 0)
        cout << "Technique: " << "Local Binary Pattern" << " with " << maskSize << "x" << maskSize << " pixel mask" << endl;
    else if (technique == 1) {      
        cout << "Technique: " << "Compound Local Binary Pattern" << " with " << maskSize << "x" << maskSize << " pixel mask and ";
        if (direction == 0)
            cout << "anti-clockwise rotation." << endl;
        else if (direction == 1)
            cout << "clockwise rotation." << endl;
    }

    // Print blank line
    cout << endl;
}

// Prints help text
void printHelp () {

    string repoURL = "https://github.com/fhamm/CiLBP";

    // Print header
    cout << "CiLBP - UFPR" << endl;
    cout << "Console integrated local binary pattern." << endl;
    cout << "Developed by Felipe Hamm at Universidade Federal do Paraná." << endl;

    cout << endl;

    // Print input arguments manual
    cout << "+------+--------------------+--------------------+---------------------------------------+" << endl;
    cout << "| Flag |        Name        |      Argument      |              Description              |" << endl;
    cout << "+------+--------------------+--------------------+---------------------------------------+" << endl;
    cout << "|  -i  |   Input file name  |     Image file     |       Sets input image file name      |" << endl;
    cout << "+------+--------------------+--------------------+---------------------------------------+" << endl;
    cout << "|  -o  |  Output file name  |     Image file     |      Sets output image file name      |" << endl;
    cout << "+------+--------------------+--------------------+---------------------------------------+" << endl;
    cout << "|  -t  |      Technique     |       0 or 1       |        0 sets technique to LBP        |" << endl;
    cout << "|      |                    |                    |        1 sets technique to CLBP       |" << endl;
    cout << "+------+--------------------+--------------------+---------------------------------------+" << endl;
    cout << "|  -m  |  Mask size (m x m) | Any number that is |                                       |" << endl;
    cout << "|      |                    |  odd, natural and  |          Sets mask dimensions         |" << endl;
    cout << "|      |                    |  larger than two.  |                                       |" << endl;
    cout << "+------+--------------------+--------------------+---------------------------------------+" << endl;
    cout << "|  -d  | Rotation Direction |       0 or 1       | 0 sets rotation to counter-clockwise  |" << endl;
    cout << "|      |                    |                    |      1 sets rotation to clockwise     |" << endl;
    cout << "+------+--------------------+--------------------+---------------------------------------+" << endl;
    cout << "|  -w  |    Output Window   |          -         |          Shows output window          |" << endl;
    cout << "+------+--------------------+--------------------+---------------------------------------+" << endl;
    cout << "|  -h  |        Help        |          -         |            Shows help text            |" << endl;
    cout << "+------+--------------------+--------------------+---------------------------------------+" << endl;

    cout << endl;

    // Print Github page
    cout << "For more help, visit: " << repoURL << endl;

    cout << endl;

    /*
    +------+--------------------+--------------------+---------------------------------------+
    | Flag |        Name        |      Argument      |              Description              |
    +------+--------------------+--------------------+---------------------------------------+
    |  -i  |   Input file name  |     Image file     |       Sets input image file name      |
    +------+--------------------+--------------------+---------------------------------------+
    |  -o  |  Output file name  |     Image file     |      Sets output image file name      |
    +------+--------------------+--------------------+---------------------------------------+
    |  -t  |      Technique     |       0 or 1       |        0 sets technique to LBP        |
    |      |                    |                    |        1 sets technique to CLBP       |
    +------+--------------------+--------------------+---------------------------------------+
    |  -m  |  Mask size (m x m) | Any number that is |                                       |
    |      |                    |  odd, natural and  |          Sets mask dimensions         |
    |      |                    |  larger than two.  |                                       |
    +------+--------------------+--------------------+---------------------------------------+
    |  -d  | Rotation Direction |       0 or 1       | 0 sets rotation to counter-clockwise  |
    |      |                    |                    |      1 sets rotation to clockwise     |
    +------+--------------------+--------------------+---------------------------------------+
    |  -w  |    Output Window   |          -         |          Shows output window          |
    +------+--------------------+--------------------+---------------------------------------+
    |  -h  |        Help        |          -         |            Shows help text            |
    +------+--------------------+--------------------+---------------------------------------+
    */
}