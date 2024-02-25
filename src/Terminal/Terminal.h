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
};
