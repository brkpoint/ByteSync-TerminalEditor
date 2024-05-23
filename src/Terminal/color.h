#include <iostream>
#include <string>

using namespace std;

namespace color {
    string rgb(int r, int g, int b, string text) {
        return "\033[38;2;" + r + ';' + g + ';' + b + 'm' + text + "\33[0m";
    }

    string rgb_background(int r, int g, int b, string text) {
        return "\033[48;2;" + r + ';' + g + ';' + b + 'm' + text + "\33[0m";
    }
}
