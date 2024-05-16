#include <iostream>
#include <string>
#include <vector>

#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

using namespace std;

struct winsize w;
struct winsize wl;

vector<string> buffer;

bool sizeChanged() {
    bool changed = (w.ws_col != wl.ws_col || w.ws_row != wl.ws_row);

    wl = w;

    return changed;
}

void termInit() {

}

void nextFrame() {
    ioctl(0, TIOCGWINSZ, &w);
}

void text(int x, int y, string text) {

}

void draw() {
    
}
