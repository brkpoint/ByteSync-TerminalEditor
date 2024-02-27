#include "../incld.h"

#pragma once

struct TerminalData {
    int width; // width in px
    int height; // height in px

    int widthCH; // width in chars
    int heightCH; // height in chars
};

namespace Terminal {
    TerminalData GetData(); // terminal data thing
    // void printl(string line) {
    //     cout << line << endl;
    //     printf("%c[%d;%df", 0x1b, 0, ); // setting the cursor pos 
    // }
};
