#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

// Check if input arguments are valid
bool isInputValid (int argc, char **argv);

// Gets input file name from arguments
std::string getInputFileName (int argc, char **argv);

// Gets output file state from arguments
bool getOutputFileState (int argc, char **argv);

// Gets output file name from arguments
std::string getOutputFileName (int argc, char **argv);

// Gets technique type from arguments
int getTechnique (int argc, char **argv);

// Gets technique type from arguments
int getMaskSize (int argc, char **argv);

// Gets CLBP direction from arguments
int getDirection (int argc, char **argv);

// Gets output window state from arguments
bool getOutputWindowState (int argc, char **argv);

// Gets output window state from arguments
bool getHelpState (int argc, char **argv);

// Print process information
void printInfo (int argc, char **argv);
