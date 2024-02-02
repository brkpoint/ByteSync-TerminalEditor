#include "TerminalEngine.h"

void TerminalEngine::setup() {
    system("stty raw");
}

int TerminalEngine::start() {   
    while(running) {
        input();
        if (keycode == 13) return 0;
        onUpdate();

        onRender();
    }
    system("stty cooked");
    cout << endl;
    return exitcode;
}

void TerminalEngine::input() {
    //todo
}