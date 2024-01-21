#include <ft2build.h>
#include <iostream>
#include FT_FREETYPE_H
#include "src/Freetype.h"

#define PROJECT_NAME "Font2Img"

int main(int argc, char **argv) {
    Freetype freetype;

    if (argc != 1) {
        std::cout << argv[0] << "takes no arguments.\n";
        return 1;
    }
    std::cout << "This is project " << PROJECT_NAME << ".\n";

    return 0;
}
