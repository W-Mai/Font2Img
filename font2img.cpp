#include <ft2build.h>
#include <iostream>
#include FT_FREETYPE_H
#include "src/Freetype.h"

int main(int argc, char **argv) {
    Freetype freetype;

    auto face = freetype.newFace(
        "/Users/w-mai/Projects/X-TRACK-EVO-lv-flex-tester/Vendor/Simulator/res/"
        "MiSans-Regular.ttf",
        0
    );
    face->setSize(32);

    // rotation 30 deg
    auto x_scale = 1.8f;
    auto deg     = 30.0f;
    auto rad     = deg * 3.14159265358979323846 / 180.0f;
    face->addMatrix(cos(rad) * x_scale, sin(rad), -sin(rad), cos(rad));

    auto glyph = face->getGlyph(0x9f98, Bitmap);

    std::cout << "Width: " << glyph->getWidth() << std::endl;
    std::cout << "Height: " << glyph->getHeight() << std::endl;
    std::cout << "Advance: " << glyph->getAdvance() << std::endl;

    char color[] = {' ', ' ', '.', '*', '#', '@'};

    auto data    = glyph->render();
    for (int i = 0; i < glyph->getRows(); i++) {
        for (int j = 0; j < glyph->getPitch(); j++) {
            auto val = data[i * glyph->getPitch() + j] / 51;
            std::cout << color[val];
        }
        std::cout << std::endl;
    }
    return 0;
}
