#include "TerminalEngine.h"

static int keycode;
static int lastkeycode;

TerminalEngine::TerminalEngine() {
    //system("stty raw");
    inputManager = new TerminalInput();

    running = true;
    keycode = -1;
    lastkeycode = -1;
    exitcode = 0;
}

TerminalEngine::~TerminalEngine() {
    delete inputManager;

    running = false;
    keycode = -1;
    lastkeycode = -1;
    exitcode = 0;
}

int TerminalEngine::start() {
    inputManager->openInput();
    while(running) {
        //input
        {
            keycode = inputManager->readInput();
            if (keycode == 13) return exitcode = 0;
            lastkeycode = keycode;
        }
        onUpdate(keycode);

        onRender();
    }
    inputManager->closeInput();
    cout << endl;
    return exitcode;
}

void TerminalEngine::stop() {
    running = false;
}