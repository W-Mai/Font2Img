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

enum FreetypeGlyphRenderMode : uint8_t {
    Bitmap = 0,
    Outline,
    SVG,
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
    void addMatrix(double xx, double xy, double yx, double yy);

    pImpl *getImpl() const;
    std::shared_ptr<Glyph> getGlyph(uint32_t unicode, FreetypeGlyphRenderMode mode);

    ~Face();
};

class Glyph {
    struct pImpl;
    pImpl *impl;

public:
    Glyph(Face *face, uint32_t unicode, FreetypeGlyphRenderMode mode);

    uint32_t getPitch() const;
    uint32_t getWidth() const;
    uint32_t getHeight() const;
    uint32_t getRows() const;
    uint32_t getAdvance() const;
    uint32_t getBearingX() const;
    uint32_t getBearingY() const;

    std::shared_ptr<uint8_t[]> render() const;

    ~Glyph();
};

#endif//FONT2IMG_FREETYPE_H
