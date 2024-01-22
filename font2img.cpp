#include <ft2build.h>
#include <iostream>
#include FT_FREETYPE_H
#include "src/Freetype.h"

int main(int argc, char **argv) {
    Freetype freetype;

    auto face = freetype.newFace("./res/NotoColorEmoji-Regular.ttf", 0);
    face->setSize(32);
    auto glyph = face->getGlyph(0x1f601, Bitmap);

    std::cout << "Width: " << glyph->getWidth() << std::endl;
    std::cout << "Height: " << glyph->getHeight() << std::endl;
    std::cout << "Advance: " << glyph->getAdvance() << std::endl;

    return 0;
}
