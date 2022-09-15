/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#include <cstdlib>
#include <cmath>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#pragma once

class Image : public cs225::PNG {
    private:

    public:
    void scale(double factor);
    void scale(unsigned w, unsigned h);

    void saturate();
    void saturate(double amount);

    void lighten();
    void lighten(double);	

    void darken(double);
    void darken();

    void desaturate();
    void desaturate(double);
    
    void rotateColor(double degrees);

};