#include "Terminal.h"

using namespace Terminal;

TerminalData Terminal::GetData() {
    TerminalData data;

    // getting the height and width of the terminal in pixles and chars
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    data.widthCH = w.ws_row; // char width
    data.heightCH = w.ws_col; // char height

    data.width = w.ws_xpixel; // normal width
    data.height = w.ws_ypixel; // normal height

    return data;
}
