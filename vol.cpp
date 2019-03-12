#include "vol.h"

using namespace KTMNYA001;


KTMNYA001::VolImage::VolImage(){

}

KTMNYA001::VolImage::~VolImage(){

}

bool KTMNYA001::VolImage::readImages(std::string baseName){
    return true;
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
