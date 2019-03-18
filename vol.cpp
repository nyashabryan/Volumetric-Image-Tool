#include <ostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include<string>

#include "vol.h"

using namespace KTMNYA001;
using namespace std;

/**
 * The default constructor.
 * Set the image height and width to 0;
 * Initiate the vector to empty;
 */
KTMNYA001::VolImage::VolImage(){
    width = 0;
    height = 0;
}

KTMNYA001::VolImage::~VolImage(){

}

/**
 * Reads the image from the raw files using the values of the 
 * image in the header file.
 */
bool KTMNYA001::VolImage::readImages(std::string baseName){
    // Make the filename
    string filename = baseName + ".data";

    // Open the file stream to the header file.
    ifstream ifs(filename);

    // Get the line in the header file.
    string line;
    getline(ifs, line);

    //Close the file stream
    ifs.close();

    // Declare istringstream
    istringstream iss(line);

    // Take in the width height and numberOfImages
    iss >> width;
    iss >> height;
    iss >> numberOfImages;

    // Declare the rawfilename
    string rawFilename;

    // Loop to load the images into the vector.
    for(int i=0; i < numberOfImages; i++){

        // Build the filename of the image slice
        stringstream ss;
        ss << i;
        rawFilename = baseName + ss.str() + ".raw";

        // Open a file stream to the image slice 
        ifstream ifs(rawFilename);

        // Each image is represented by char** and each row is represented by char*
        char **sliceptr = new char* [height];

        for(int rowNo = 0; rowNo < height; rowNo++){

            // Allocate memory for space
            sliceptr[rowNo] = new char[width];

            // Iterate through the width inserting values
            for (int colNo = 0; colNo < width; colNo++){
                ifs >> sliceptr[rowNo][colNo];
            }
        }

        // Close the stream
        ifs.close();

        slices.push_back(sliceptr);
    }
    
    cout << 
}

void KTMNYA001::VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix){
    return ;
}

void KTMNYA001::VolImage::extract(int sliceId, std::string output_prefix){
    return ;
}

int KTMNYA001::VolImage::volImageSize(void){
    return 1;
}
