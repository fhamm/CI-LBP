# CiLBP

Developed by the Department of Informatics of Universidade Federal do Paraná.

## Installation

First, check if you have *G++*, *OpenCV* and *Make* installed in your machine.

Then, to install the program, just clone this repository and run `make`. It will compile everything and produce an executable file.

## Usage

The following table shows the input arguments and their respective functions:

|  Flag  |          Name         |                                    Argument                                   |                                         Description                                        |
|:------:|:---------------------:|:-----------------------------------------------------------------------------:|:------------------------------------------------------------------------------------------:|
| **-i** |   *Input file name*   |                                  *Image file*                                 |                                 Sets input image file name                                 |
| **-o** |   *Output file name*  |                                  *Image file*                                 |                                 Sets output image file name                                |
| **-t** |      *Technique*      |                                **0** *or* **1**                               |                **0** sets technique to LBP<br> **1** sets technique to CLBP                |
| **-m** |  *Mask size (m x m)*  | *Any number that is*<br> **odd**, **natural** *and*<br>  **larger than two**. |                                    Sets mask dimensions                                    |
| **-d** | *Rotation Direction** |                                **0** *or* **1**                               | **0** sets rotation to **counter-clockwise**<br>  **1** sets rotation to **clockwise**<br> |
| **-w** |    *Output Window*    |                                     **-**                                     |                                     Shows output window                                    |
| **-h** |         *Help*        |                                     **-**                                     |                                       Shows help text                                      |

**Only needed when using CLBP technique*.

## Disclaimer

This program is still under development. Therefore, many features may be missing.
