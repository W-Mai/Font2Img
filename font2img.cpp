#include <ft2build.h>
#include <iostream>
#include FT_FREETYPE_H
#include "src/Freetype.h"

int main(int argc, char **argv) {
    Freetype freetype;

    auto face = freetype.newFace("./res/NotoColorEmoji-Regular.ttf", 0);
    face->setSize(32);

    return 0;
}
