#include "TerminalEngine.h"

static int keycode;
static int lastkeycode;

TerminalEngine::TerminalEngine() {
    //system("stty raw");
    inputManager = new TerminalInput();
    running = true;
    keycode = 0;
    exitcode = 0;
}

TerminalEngine::~TerminalEngine() {
    running = NULL;
    keycode = NULL;
    lastkeycode = NULL;
    exitcode = NULL;
}

int TerminalEngine::start() {
    inputManager->openInput();
    while(running) {
        if (inputManager->isInputAvaiable()) keycode = inputManager->readInput();
        if (keycode == 13) return exitcode = 0;
        if (keycode != lastkeycode) {
            cout << keycode;
            lastkeycode = keycode;
        }
        onUpdate();

        onRender();
    }
    inputManager->closeInput();
    delete inputManager;
    //system("stty cooked");
    cout << endl;
    return exitcode;
}