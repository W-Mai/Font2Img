//
// Created by W-Mai on 2024/1/20.
//

#include "Freetype.h"

#include "ft2build.h"
#include FT_FREETYPE_H

struct Freetype::pImpl {
    FT_Library library;
};

Freetype::Freetype() {
    impl = new Freetype::pImpl;

    FT_Init_FreeType(&impl->library);
}
Freetype::~Freetype() {
    FT_Done_FreeType(impl->library);

    delete impl;
}
