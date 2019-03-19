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
        delete slices[i];
    }   
}

/**
 * Reads the image from the raw files using the values of the 
 * image in the header file.
 */
bool KTMNYA001::VolImage::readImages(std::string baseName){

    cout <<"Reading images started." << endl;
    // Make the filename
    string filename = baseName + ".dat";

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
        ifstream ifs(rawFilename, ios::binary);
        if(!ifs.good()){
            cerr << "Error." << endl;
            exit(1);
        }

        // Allocate memory of the 2D array
        // Each image is represented by har** and each row is represented by char*
        slices[i] = new u_char* [height];

        for(int row = 0; row < height; row++){
            slices[i][row] = new u_char[width];
        }

        // Create a 1 byte buffer
        char buffer[1];

        // Initiate col and row
        int col = 0;
        int row = 0;

        // Read file until its end.
        while(!ifs.eof()){
            //Read into buffer a size of u_char
            ifs.read(buffer, sizeof(u_char));
            // Assign the read value to the 2D array
            slices[i][row][col] = (u_char) *buffer;
            // Update the array indexing
            col = (col + 1) % width;
            if(col == 0) row++;
            // Break before null character
            if(row == height) break;
        }
        
        // Close the file stream
        ifs.close();
    }
    // Alert all images have been loaded successfully.
    cout << "Loaded fully loaded the images. " << endl;
}

void KTMNYA001::VolImage::diffmap(int sliceI, int sliceJ, std::string output_prefix){
    
    // declare the difference slice
    u_char ** difference = new u_char *[height];

    // Allocate memory for the cols of the difference
    for(int i = 0; i < height; i++)
        difference[i] = new u_char[width];

    // Calculate the difference 
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            difference[row][col] = (u_char)(abs((float)slices[sliceI][row][col] - (float)slices[sliceJ][row][col])/ 2);
        }
    }
    
    // Output the difference to a file

    // declare the filenames
    string headerFilename = output_prefix + ".dat";
    string rawFilename = output_prefix + ".raw";

    // Write the header file
    ofstream headerOfs(headerFilename, ios::binary);

    headerOfs << width << " " << height << " " << 1;
    // Close header file
    headerOfs.close();

    // Write the output raw image file 
    ofstream rawOfs(rawFilename, ios::binary);
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            rawOfs << difference[row][col];
        }
    }
    rawOfs.close();

    // Deallocate the difference memory
    for(int i=0; i < height; i++){
        delete difference[i];
    }
    delete difference;

    cout <<"Successfully calculated the distance between image: "
        << sliceI << " and image: " << sliceJ << endl;
}

/**
 * Outputs a selected slice to an output.
 */
void KTMNYA001::VolImage::extract(int sliceId, std::string output_prefix){

    cout << "Extracting slice number: " << sliceId << endl;

    // Initiate the file names 
    string headerFilename = output_prefix + ".dat";
    string rawFilename = output_prefix + ".raw";

    // Write the header file
    ofstream headerOfs(headerFilename, ios::binary);

    headerOfs << width << " " << height << " " << 1;
    // Close header file
    headerOfs.close();

    // Write the output raw image file 
    ofstream rawOfs(rawFilename, ios::binary);
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            rawOfs << slices[sliceId][row][col];
        }
    }

    rawOfs.close();

    cout << "Successfully extracted the image file."  << endl;
    return;
}

int KTMNYA001::VolImage::volImageSize(void){
    double data_bytes = height * width;
    double pointer_bytes = 0;

    //for (int i =0; i < )

    return 1;
}


void KTMNYA001::VolImage::extractRow(int rowId, std::string output_prefix){

    // allocate the space for new image
    u_char ** row_slice = new u_char *[numberOfImages];

    for(int i = 0; i < numberOfImages; i++){
        row_slice[i] = new u_char[width];
    }

    // Assign the rows rowId from each image as rows
    for(int imageId = 0; imageId < numberOfImages; imageId++){
        slices[imageId][rowId] = row_slice[imageId];
    }

    // Output the difference to a file

    // declare the filenames
    string headerFilename = output_prefix + ".dat";
    string rawFilename = output_prefix + ".raw";

    // Write the header file
    ofstream headerOfs(headerFilename, ios::binary);

    headerOfs << width << " " << numberOfImages << " " << 1;
    // Close header file
    headerOfs.close();

    // Write the output raw image file 
    ofstream rawOfs(rawFilename, ios::binary);
    for(int row = 0; row < numberOfImages; row++){
        for(int col = 0; col < width; col++){
            rawOfs << row_slice[row][col];
        }
    }
    rawOfs.close();

    // Deallocate the difference memory
    for(int i=0; i < numberOfImages; i++){
        delete row_slice[i];
    }
    delete row_slice;

}