//
// Created by W-Mai on 2024/1/20.
//

#ifndef FONT2IMG_FREETYPE_H
#define FONT2IMG_FREETYPE_H

#include <memory>

class Freetype;

class Face;

class Glyph;


class Freetype {
    struct pImpl;
    pImpl *impl;

public:
    Freetype();
    ~Freetype();

    pImpl *getImpl() const;
    std::shared_ptr<Face> newFace(const char *path, uint32_t index = 0);
};

class Face {
    struct pImpl;
    pImpl *impl;

public:
    Face(Freetype *ft, const char *path, uint32_t index = 0);

    ~Face();
};

class Glyph {
    struct pImpl;
    pImpl *impl;

public:
};

#endif//FONT2IMG_FREETYPE_H
