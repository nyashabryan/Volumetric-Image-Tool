#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include "vol.h"

using namespace std;
using namespace KTMNYA001;

static int argcount;
static char** args;

int main(int argc, char** argv){
    argcount = argc;
    args = argv;
    if(argcount < 2) {
        cerr << "Insufficient number of args. Exitting..." << endl;
        exit(1);
    }

    // Build and load the volimage
    VolImage volImage = VolImage();
    string baseName = string(argv[1]);
    volImage.readImages(baseName);

    // Check if optional parameters given
    if(argcount > 2 ){
        string output_prefix;
        string buffer;
        // Choose what mode to run.
        string choice = string(argv[2]);
        if (choice == "-d"){ // Difference mode
            // Check for enough args
            if (argcount < 6){
                cerr << "Insufficient number of arguments for the difference mode." << endl;
                exit(1);
            } else if(argcount > 6){
                cerr << "Too many arguments have been entered" << endl;
                exit(1);
            } else {
                int i;
                int j;

                buffer = string(argv[3]);
                istringstream iss(buffer);
                iss >> i;
                buffer = string(argv[4]);
                istringstream iss2(buffer);
                iss2 >> j;

                output_prefix = string(argv[5]);
                volImage.diffmap(i, j, output_prefix);
            }

        } else if (choice == "-x"){ // Extraction mode
            // Check for the number of inputs 
            if (argcount < 5){
                cerr << "Insufficient number of arguments for the extraction mode." << endl;
                exit(1);
            } else if(argcount > 5){
                cerr << "Too many arguments have been entered." << endl;
                exit(1);
            } else {
                int i;
                buffer = string(argv[3]);
                istringstream iss(buffer);
                iss >> i;
                output_prefix = string(argv[4]);

                // Run the extraction method
                volImage.extract(i, output_prefix);
            }

        } else if (choice == "-g"){ // row Extract mode
            // Check for the number of inputs 
            if (argcount < 5){
                cerr << "Insufficient number of arguments for the row extraction mode." << endl;
                exit(1);
            } else if(argcount > 5){
                cerr << "Too many arguments have been entered." << endl;
                exit(1);
            } else {
                int i;
                buffer = string(argv[3]);
                istringstream iss(buffer);
                iss >> i;
                output_prefix = string(argv[4]);

                // Run the extraction method
                volImage.extractRow(i, output_prefix);
            }

        } else {
            cerr << "You are selected in invalid option. Try again." << endl;
        }
    }
    
    // Print the final statement to console

    std::cout << "Number of images: " << volImage.getNumberOfImages() << std::endl;
    std::cout << "Number of bytes required: " << volImage.volImageSize() << std::endl;
    
    return 0;
}