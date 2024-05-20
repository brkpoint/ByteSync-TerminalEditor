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

    vector<string> buffer;

    bool sizeChanged() {
        bool changed = (w.ws_col != wl.ws_col || w.ws_row != wl.ws_row);

        wl = w;

        return changed;
    }

    void getInfo() {
        ioctl(0, TIOCGWINSZ, &w);
    }

    void cursor(int x, int y) {

    }

    void clear() {
        system("clear");
        buffer.clear();
        for (int i = 0; i < w.ws_row - 1; i++) {
            buffer.push_back(string(w.ws_col, ' '));
        }    
    }

    void render() {
        for (int i = 0; i < w.ws_row - 1; i++) {
            printf("\033[%d;%dH%s", i, 0, buffer.at(i).c_str());
        }
    }

    void print(int x, int y, string text) {
        for (int i = 0; i < text.length(); i++) {
            buffer.at(y).at(x + i) = text.at(i);
        }
    }

    void print(int x, int y, char ch) {
        buffer.at(y).at(x) = ch;
    }
}
