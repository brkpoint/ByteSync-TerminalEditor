#include <iostream>
#include <string>
#include <vector>

#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

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
        printf("\033[%d;%dH", y, x);
    }

    void clear() {
        system("clear");
        for (int i = 0; i < w.ws_row - 1; i++) {
            printf(string(w.ws_col, ' ').c_str());
        }
        terminal::cursor(0, 1);
    }

    void print(int x, int y, string text) {
        printf("\033[%d;%dH%s", y, x, text.c_str());
    }
}
