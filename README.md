Volumetric Image Tool
======================

Getting Started
------------------------
Get ready your copy of images to be run by the program. Each stack of images should be in one folder and should include a `.dat` file. The `.dat` file should contain the width, height of images and the number of images.

Building Application
-------------------------
1. `make depend` Build the dependencies of the application
2. `make` Build the entire application


Running Application
--------------------
There are 4 running modes of the application. The application can only run one mode at a time. 

`volimage <imageBase> [-d i j output_file_name] [-x i output_file_name] [-g i output_file_name]`

Run Modes
------------

1. No arguments: Builds the object and exists.
2. `-g` Extract Row: Builds image from same row in all images. 
3. `-d` Calculate difference: Builds the difference image from two files i and j index.
4. `-x` Extract slice: Builds a particular slice of image to output.

Author
-----------
Nyasha Bryan Katemauswa for the University of Cape Town