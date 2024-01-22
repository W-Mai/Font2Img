//
// Created by W-Mai on 2024/1/20.
//

#ifndef FONT2IMG_FREETYPE_H
#define FONT2IMG_FREETYPE_H

#include <memory>

class Freetype;

class Face;

class Glyph;

enum FreetypeFaceStyle : uint8_t {
    Regular    = 0,
    Bold       = 1 << 0,
    Italic     = 1 << 2,
    BoldItalic = Bold | Italic
};

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

    void setStyle(FreetypeFaceStyle style);
    void setSize(uint32_t size);

    ~Face();
};

class Glyph {
    struct pImpl;
    pImpl *impl;

public:
};

#endif//FONT2IMG_FREETYPE_H
