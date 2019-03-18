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

/**
 * The class deconstructor.
 * Removes all the automatic variables instantiated in the program.
 */
KTMNYA001::VolImage::~VolImage(){

    /** Iterate throught the images and delete all the
     * automatic pointers
     */
    for(int i = 0; i < numberOfImages; i++){
        for(int j = 0; j < height; j++){
            delete slices[i][j];
        }
    }   
}

/**
 * Reads the image from the raw files using the values of the 
 * image in the header file.
 */
bool KTMNYA001::VolImage::readImages(std::string baseName){

    cout <<"Reading images started." << endl;
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

    slices = vector<u_char **>(numberOfImages);
    string rawFilename;

    // Loop to load the images into the vector.
    for(int i=0; i < numberOfImages; i++){

        // Print out the image number of the image being loaded.
        cout << "Image number: " << i << endl;

        // Build the image name.
        stringstream ss;
        ss << i;
        rawFilename = baseName + ss.str() + ".raw";

        // Open a file stream to the image slice 
        ifstream ifs(rawFilename);
        if(!ifs.good()){
            cerr << "Error." << endl;
            exit(1);
        }

        // Each image is represented by har** and each row is represented by char*
        slices[i] = new u_char* [height];

        for(int rowNo = 0; rowNo < height; rowNo++){

            // Allocate memory for space
            slices[i][rowNo] = new u_char[width];

            // Iterate through the width inserting values
            for (int colNo = 0; colNo < width; colNo++){
                ifs >> slices[i][rowNo][colNo];
            }
        }

        // Close the stream
        ifs.close();
    }
    
    cout << "Loaded fully loaded the images. " << endl;
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
