#include <iostream>
#include <string>
#include "vol.h"

using namespace std;
using namespace KTMNYA001;

static int argcount;
static char** args;

int main(int argc, char** argv){
    argcount = argc;
    args = argv;
    
    std::cout << "Running" << std::endl;
    std::cout << argcount << std::endl;
    std::cout << argv << std::endl;


    // Declare the final print out variables.
    int numberOfImages;
    int numberOfBytesRequired;

    string output_prefix = "output";
    // Create the volImageObject
    VolImage volImage = VolImage();
    string baseName = "./brain_mri_raws/brain_mri_raws/MRI";
    volImage.readImages(baseName);
    //volImage.extract(5, output_prefix);
    volImage.diffmap(5, 10, output_prefix);
    if (argcount < 2) {


    } else if (argcount == 5){
        
        std::cout << "Argument 1 " << args[0]  << std::endl;
        std::cout << "Argument 2 " << args[1]  << std::endl;
        std::cout << "Argument 3 " << args[2]  << std::endl; 
        std::cout << "Argument 4 " << args[3]  << std::endl;

    } else if (argcount == 6){

    } else {

    }

    // Print the final statement to console

    std::cout << "Number of images: " << numberOfImages << std::endl;
    std::cout << "Number of bytes required: " << numberOfBytesRequired << std::endl;
    
    return 0;
}