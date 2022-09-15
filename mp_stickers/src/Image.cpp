
#include "Image.h"

using namespace std;
void Image::scale(double factor) {
    // for(unsigned int i = 0; i < Image::width(); i++) {
    //     for (unsigned int j = 0; j < Image::height(); j++) {
    //         cs225::HSLAPixel& p = getPixel(i, j);
    //     }
    // }
    Image::resize(width()*factor, height()*factor);

}


void Image::saturate(double amount) {
    for(unsigned int i = 0; i < Image::width(); i++) {
        for (unsigned int j = 0; j < Image::height(); j++) {
            cs225::HSLAPixel& p = getPixel(i, j);
            if(p.s < 1) {
                p.s = p.s + amount;
            }
            if (p.s > 1) {
                p.s = 1;
            }
        }
    }
}
void Image::lighten	() {
    for(unsigned int i = 0; i < Image::width(); i++) {
        for (unsigned int j = 0; j < Image::height(); j++) {
            cs225::HSLAPixel& p = getPixel(i, j);
            if (p.l < 1) {
                p.l = p.l + 0.1;
            }
            if (p.l > 1) {
                p.l = 1;
            }
        }

    }
}	

void Image::darken(double amount) {
    for(unsigned int i = 0; i < Image::width(); i++) {
        for (unsigned int j = 0; j < Image::height(); j++) {
            cs225::HSLAPixel& p = getPixel(i, j);
            if (p.l > 0) {
                p.l = p.l - amount;
            }
            if (p.l < 0) {
                p.l = 0;
            } 
        }
    }
}



void Image::scale(unsigned w, unsigned h) {
    unsigned wid = Image::width();
    unsigned heig = Image::height();
    unsigned aspect_ratio = wid/heig;
    if (h > w) {
        w = h * aspect_ratio;
    }
    if (w > h) {
        h = w / aspect_ratio;
    }
    unsigned h_factor = h/heig;
    unsigned w_factor = w/wid;
    Image::resize(width()*w_factor, height()*h_factor);
}

void Image::saturate() {
    for(unsigned int i = 0; i < Image::width(); i++) {
        for (unsigned int j = 0; j < Image::height(); j++) {
            cs225::HSLAPixel& p = getPixel(i, j);
            if(p.s < 1) {
                p.s = p.s + 0.1;
            }
            if (p.s > 1) {
                p.s = 1;
            }
        }
    }
}
 

void Image::lighten(double amount) {
    for(unsigned int i = 0; i < Image::width(); i++) {
        for (unsigned int j = 0; j < Image::height(); j++) {
            cs225::HSLAPixel& p = getPixel(i, j);
            if (p.l < 1) {
                p.l = p.l + amount;
            }
            if (p.l > 1) {
                p.l = 1;
            }
        }
    }
}


void Image::darken() {
    for(unsigned int i = 0; i < Image::width(); i++) {
        for (unsigned int j = 0; j < Image::height(); j++) {
            cs225::HSLAPixel& p = getPixel(i, j);
            p.l = p.l - 0.1;
        }
    }
}

void Image::desaturate() {
    for(unsigned int i = 0; i < Image::width(); i++) {
        for (unsigned int j = 0; j < Image::height(); j++) {
            cs225::HSLAPixel& p = getPixel(i, j);
            p.s = p.s - 0.1;
        }
    }
}
void Image::desaturate(double amount) {
    for(unsigned int i = 0; i < Image::width(); i++) {
        for (unsigned int j = 0; j < Image::height(); j++) {
            cs225::HSLAPixel& p = getPixel(i, j);
            p.s = p.s - amount;
        }
    }
}


void Image::rotateColor	(double degrees) {
    for(unsigned int i = 0; i < Image::width(); i++) {
        for (unsigned int j = 0; j < Image::height(); j++) {
            cs225::HSLAPixel& p = getPixel(i, j);
        
            p.h = p.h + degrees;
    
            if (p.h > 360) {
                p.h -= 360;
            }
            if (p.h < 0) {
                p.h += 360;
            }
        }
    }
}