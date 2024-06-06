#pragma once

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

namespace input {
    struct termios oldt, newt;
    int oldf;

    void inpinit() {
        //cout << "\x1b[?25l" << flush;
        system("stty raw");
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    }

    void inpend() {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        system("stty cooked");
        cout << "\x1b[?25h" << flush;
    }
}
