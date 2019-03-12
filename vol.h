#ifndef VOL_H
#define VOL_H
#endif

#include <vector>
#include <string>


namespace KTMNYA001{

    class VolImage
    {
        private: // private members 
        int width, height; // width and height of the image stack.
        std::vector<unsigned char**> slices;


        public: // public members
        VolImage(); // The default constructor. 
        ~VolImage(); // The default destructor.

        bool readImages(std::string baseName);


        void diffmap(int sliceI, int sliceJ, std::string output_prefix);


        void extract(int sliceId, std::string output_prefix);

        int volImageSize(void);

    };

}
