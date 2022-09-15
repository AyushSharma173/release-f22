/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include <iostream>
#include <vector>
#include "Image.h"
#include <cstdlib>
#include <cmath>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using namespace std;
struct Sticker {
    int x;
    int y;
    Image* image;
};

class StickerSheet {
    public:
    StickerSheet(const Image &picture, unsigned max);
    ~StickerSheet();
    StickerSheet(const StickerSheet &other);
    int addSticker(Image &other, unsigned x, unsigned y);
    void changeMaxStickers(unsigned max);
    Image* getSticker(unsigned index);
    const StickerSheet & operator=(const StickerSheet & other);
    void removeSticker(unsigned index);
    Image render()	const;
    bool translate(unsigned index, unsigned x, unsigned y);

    private:
    vector<Sticker> _collection;
    const Image* _base_image;
    int _max_stickers;
};

