#include <ft2build.h>
#include <iostream>
#include FT_FREETYPE_H

#define PROJECT_NAME "Font2Img"

int main(int argc, char **argv) {
    FT_Library library;
    FT_Init_FreeType(&library);

    if (argc != 1) {
        std::cout << argv[0] << "takes no arguments.\n";
        return 1;
    }
    std::cout << "This is project " << PROJECT_NAME << ".\n";
    std::cout << library << std::endl;

    FT_Done_FreeType(library);
    return 0;
}
