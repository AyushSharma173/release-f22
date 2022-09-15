/**
 * @file sketchify.cpp
 * Implementation of the sketchify function.
 */
#pragma GCC diagnostic ignored "-Wuninitialized"
#include <cstdlib>
#include <cmath>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;
using namespace std;
/**
 * Creates a new output image.
 * @param w width of the image
 * @param h height of the image
 * @return a pointer to the newly-created image
 */
PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}

/**
 * Used to customize the color of the sketchified image.
 * @return a pointer to the color to use when sketchifying
 */
HSLAPixel* myFavoriteColor() {
    static HSLAPixel p(11, 0.8, 0.5);
    return &p;
}

void sketchify(std::string inputFile, std::string outputFile) {
    // Load in.png
    PNG* original = new PNG();
    // std::cout << "Reached line " << __LINE__ << std::endl;
    // unsigned width;
    // unsigned height;
    // std::cout << "Reached line " << __LINE__ << std::endl;
    // if (original->readFromFile(inputFile)) {
    //     std::cout << "Reached line " << __LINE__ << std::endl;
    //     width = original->width();
    //     height = original->height();
    //     std::cout << "Reached line " << __LINE__ << std::endl;
    // } else {
    //     std::cout << "Reached line " << __LINE__ << std::endl;
    //     width = 0;
    //     height = 0;
    //     std::cout << "Reached line " << __LINE__ << std::endl;
    // }
    original->readFromFile(inputFile);
    unsigned width = original->width();
    unsigned height = original->height();
    // Create out.png
    PNG* output = setupOutput(width, height);

    // Load our favorite color to color the outline
    HSLAPixel* myPixel = myFavoriteColor();

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output

    for (unsigned y = 1; y < height; y++) {
        for (unsigned x = 1; x < width; x++) {
            // // Calculate the pixel difference
            // std::cout << "Reached line " << x << std::endl;
            // std::cout << "Reached line " << y << std::endl;

            HSLAPixel& prev = original->getPixel(x - 1, y - 1);
            HSLAPixel& curr = original->getPixel(x, y);
            double diff = std::fabs(curr.h - prev.h);

            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            HSLAPixel& currOutPixel = (*output).getPixel(x, y);
            if (diff > 20) {
                currOutPixel = *myPixel;
            }
        }
    }

    // Save the output file
    output->writeToFile(outputFile);

    // Clean up memory

    // delete myPixel;

    delete output;
    delete original;
}