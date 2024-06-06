#pragma once

#include <iostream>
#include <string>

#include "../utils/string.h"

using namespace std;

namespace color {
    string rgb(int r, int g, int b, string text) {
        char buffer[100];
        snprintf(buffer, 100, "\033[48;2;%d;%d;%dm%s\33[0m", r, g, b, text.c_str());
        return buffer;
    }

    string rgb_background(int r, int g, int b, string text) {
        char buffer[100];
        snprintf(buffer, 100, "\033[48;2;%d;%d;%dm%s\33[0m", r, g, b, text.c_str());
        return buffer;
    }
}
