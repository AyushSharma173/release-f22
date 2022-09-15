
#include "StickerSheet.h"
#include <vector>
#include <iostream>
#include <vector>
#include "Image.h"
#include <cstdlib>
#include <cmath>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"


using namespace std;

    StickerSheet::StickerSheet(const Image &picture, unsigned max) {
        StickerSheet::_base_image = &picture;
        StickerSheet::_max_stickers = max; 
        // vector<Image*> _collection = new vector<Image*>;
    }



    StickerSheet::~StickerSheet() {
        // if (_collection != NULL) {
        //     _collection = NULL;
        // }
        if (_base_image != NULL) {
            _base_image = NULL;
        }
    }

    StickerSheet::StickerSheet(const StickerSheet &other) {
        _collection.clear();
        _collection = other._collection;
        _base_image = other._base_image;
        _max_stickers = other._max_stickers;

    }

    int StickerSheet::addSticker(Image &other, unsigned x, unsigned y) {
        struct Sticker sticker1;
        sticker1.image = &other;
        sticker1.x = x;
        sticker1.y = y;
        _collection.push_back(sticker1);
       return 1;
    }

    void StickerSheet::changeMaxStickers(unsigned max) {
        auto iter = _collection.begin();
        unsigned j = 0;
        while(iter != _collection.end() && j < max) {
            iter++;
            j++;
        }
        _collection.erase(iter, _collection.end());
        _max_stickers = max;
    }

    Image* StickerSheet::getSticker(unsigned index) {
        if(index > unsigned(_max_stickers) || index < 0) {
            return NULL;
        }
        unsigned i = 0;
        for (auto iter = _collection.begin(); iter != _collection.end(); iter++) {
            if (i == index) {
                return _collection[index].image;
            }
            i++;
        }
        return NULL;
    }

    const StickerSheet & StickerSheet::operator=(const StickerSheet &other){
        _collection.clear();
        _collection = other._collection;
        _base_image = other._base_image;
        _max_stickers = other._max_stickers;
        return other;
    }


    void StickerSheet::removeSticker(unsigned index) {
        vector<Sticker>::iterator it = _collection.begin();
        for (unsigned i = 0; i < index; i++) {
            it++;
        }
        _collection.erase(it);
    }

    Image StickerSheet::render() const {
        unsigned wide = _base_image->width();
        unsigned heig = _base_image->height();
        Image Img_copy(*_base_image);
        for(auto stick = _collection.begin(); stick != _collection.end(); ++stick) {
            unsigned sticker_width = stick->image->width();
            unsigned sticker_height = stick->image->height();

            for (unsigned i = 0 ; i < sticker_width; i++) {
                for (unsigned j = 0; j < sticker_height; j++) {
                    cs225::HSLAPixel& pixel = Img_copy.getPixel(i + stick->x, j + stick->y);
                    if (stick->image->getPixel(i, j).a != 0) {
                        pixel = stick->image->getPixel(i, j);
                    }

                }
            }
        }
        return Img_copy;
        }

        bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
        auto stick = _collection.begin();
        for(unsigned i = 0; i < index; i++) {
            stick++;
            if (stick == _collection.end()) {
                return false;
            }
        }
        stick->x = x;
        stick->y = y;
        return true;
    }




