//
// Created by W-Mai on 2024/1/20.
//

#ifndef FONT2IMG_FREETYPE_H
#define FONT2IMG_FREETYPE_H
class Freetype;

class Face;

class Glyph;


class Freetype {
    struct pImpl;
    pImpl *impl;

public:
    Freetype();
    ~Freetype();
};

class Face {
    struct pImpl;
    pImpl *impl;

public:
};

class Glyph {
    struct pImpl;
    pImpl *impl;

public:
};

#endif//FONT2IMG_FREETYPE_H
