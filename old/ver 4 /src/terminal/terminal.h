#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include "../utils/string.h"

using namespace std;

namespace terminal {
    struct winsize w;
    struct winsize wl;

    bool sizeChanged() {
        bool changed = (w.ws_col != wl.ws_col || w.ws_row != wl.ws_row);

        wl = w;

        return changed;
    }

    void getInfo() {
        ioctl(0, TIOCGWINSZ, &w);
    }

    void cursor(int x, int y) {
        printf("\033[%d;%dH", y + 1, x + 1);
    }

    void clear() {
        system("clear");
        for (int i = 0; i < w.ws_row - 1; i++) {
            printf("%s", string(w.ws_col, ' ').c_str());
        }
    }

    template<class T> void print(int x, int y, T text) {
        printf("\033[%d;%dH%s", y + 1, x + 1, utils::to_string(text).c_str());
    }

    void hideCursor() {
        cout << "\x1b[?25l" << flush;
    }

    void showCursor() {
        cout << "\x1b[?25h" << flush;
    }
}
