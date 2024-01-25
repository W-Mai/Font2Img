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
    FT_Matrix matrix;
};

struct Glyph::pImpl {
    Face *face;

    uint32_t unicode;
    FT_GlyphSlot slot;
    FreetypeGlyphRenderMode mode;
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

    impl->matrix = {1 << 16, 0, 0, 1 << 16};
}
Face::~Face() {
    FT_Done_Face(impl->face);

    delete impl;
}
void Face::setStyle(FreetypeFaceStyle style) {
    if (style & FreetypeFaceStyle::Italic) {
        FT_Matrix matrix = {1 << 16, 0x5800, 0, 1 << 16};
        impl->matrix     = matrix;
    }

    FT_Set_Transform(impl->face, &impl->matrix, nullptr);
    impl->style = style;
}
void Face::setSize(uint32_t size) { FT_Set_Pixel_Sizes(impl->face, 0, size); }
Face::pImpl *Face::getImpl() const { return impl; }
std::shared_ptr<Glyph>
Face::getGlyph(uint32_t unicode, FreetypeGlyphRenderMode mode) {
    return std::make_shared<Glyph>(this, unicode, mode);
}

void Face::addMatrix(double xx, double xy, double yx, double yy) {
    FT_Matrix old_matrix = impl->matrix;

    impl->matrix.xx =
        (FT_Fixed) (xx * (double) old_matrix.xx + xy * (double) old_matrix.yx);
    impl->matrix.xy =
        (FT_Fixed) (xx * (double) old_matrix.xy + xy * (double) old_matrix.yy);
    impl->matrix.yx =
        (FT_Fixed) (yx * (double) old_matrix.xx + yy * (double) old_matrix.yx);
    impl->matrix.yy =
        (FT_Fixed) (yx * (double) old_matrix.xy + yy * (double) old_matrix.yy);

    FT_Set_Transform(impl->face, &impl->matrix, nullptr);
}


/***************************
 *   FACE IMPLEMENTATION   *
 ***************************/

Glyph::Glyph(Face *face, uint32_t unicode, FreetypeGlyphRenderMode mode) {
    impl          = new Glyph::pImpl;
    impl->face    = face;
    impl->unicode = unicode;
    impl->mode    = mode;

    auto ft_face  = impl->face->getImpl()->face;
    auto flag     = FT_LOAD_DEFAULT;
    if (impl->mode == FreetypeGlyphRenderMode::SVG) { flag |= FT_LOAD_COLOR; }

    FT_Load_Char(ft_face, impl->unicode, flag);
    impl->slot = ft_face->glyph;
}

uint32_t Glyph::getPitch() const { return impl->slot->bitmap.pitch; }
uint32_t Glyph::getWidth() const { return impl->slot->metrics.width >> 6; }
uint32_t Glyph::getHeight() const { return impl->slot->metrics.height >> 6; }
uint32_t Glyph::getRows() const { return impl->slot->bitmap.rows; }
uint32_t Glyph::getAdvance() const { return impl->slot->advance.x >> 6; }
uint32_t Glyph::getBearingX() const { return impl->slot->bitmap_left >> 6; }
uint32_t Glyph::getBearingY() const { return impl->slot->bitmap_top >> 6; }

std::shared_ptr<uint8_t[]> Glyph::render() const {
    auto glyph_format = impl->slot->format;

    if (glyph_format == FT_GLYPH_FORMAT_BITMAP ||
        glyph_format == FT_GLYPH_FORMAT_OUTLINE) {

        FT_Render_Glyph(impl->slot, FT_RENDER_MODE_NORMAL);

        if (impl->slot->bitmap.buffer) {
            auto bitmap = impl->slot->bitmap;
            auto size   = bitmap.width * bitmap.rows;
            auto data   = new uint8_t[size];
            std::copy(bitmap.buffer, bitmap.buffer + size, data);
            return {data, std::default_delete<uint8_t[]>()};
        }
    } else if (glyph_format == FT_GLYPH_FORMAT_SVG) {
        throw std::runtime_error("SVG rendering is not supported yet.");
    }
}
Glyph::~Glyph() { delete impl; }
