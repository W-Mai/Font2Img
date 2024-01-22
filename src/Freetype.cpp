//
// Created by W-Mai on 2024/1/20.
//

#include "Freetype.h"

#include "ft2build.h"
#include FT_FREETYPE_H

#include <sstream>

struct Freetype::pImpl {
    FT_Library library;
};

struct Face::pImpl {
    Freetype *ft;

    FT_Face face;

    uint32_t index;
    FreetypeFaceStyle style;
};

/***************************
 * FREETYPE IMPLEMENTATION *
 ***************************/

Freetype::Freetype() {
    impl = new Freetype::pImpl;

    FT_Init_FreeType(&impl->library);
}
Freetype::~Freetype() {
    FT_Done_FreeType(impl->library);

    delete impl;
}
std::shared_ptr<Face> Freetype::newFace(const char *path, uint32_t index) {
    return std::make_shared<Face>(this, path, index);
}

Freetype::pImpl *Freetype::getImpl() const { return impl; }


/***************************
 *   FACE IMPLEMENTATION   *
 ***************************/

Face::Face(Freetype *ft, const char *path, uint32_t index) {
    impl         = new Face::pImpl;

    impl->ft     = ft;
    impl->index  = index;

    auto library = impl->ft->getImpl()->library;

    auto error   = FT_New_Face(library, path, impl->index, &impl->face);
    if (error) {
        std::stringstream ss;
        ss << "Failed to load font face: " << path << " (index " << index
           << ") With error code: " << error;
        throw std::runtime_error(ss.str());
    }
}
Face::~Face() {
    FT_Done_Face(impl->face);

    delete impl;
}
void Face::setStyle(FreetypeFaceStyle style) {
    if (style & FreetypeFaceStyle::Italic) {
        FT_Matrix matrix = {1 << 16, 0, 0, 1 << 16};
        FT_Set_Transform(impl->face, &matrix, nullptr);
    }

    impl->style = style;
}
void Face::setSize(uint32_t size) { FT_Set_Pixel_Sizes(impl->face, 0, size); }
