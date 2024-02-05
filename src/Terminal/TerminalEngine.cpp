#include "TerminalEngine.h"

static int keycode = -1;
static int lastkeycode = -1;

TerminalEngine::TerminalEngine() {
    inputManager = new TerminalInput();

    // setting the default value
    running = true;
    exitcode = 0;
}

TerminalEngine::~TerminalEngine() {
    // deleting all variables
    delete &running;
    delete &keycode;
    delete &lastkeycode;
    delete &exitcode;
}

int TerminalEngine::start() {
    inputManager->openInput(); // creating a new thread and setting input terminal variables
    onStart(); // call the virtual start
    while(running) {
        //input
        {
            keycode = inputManager->readInput();
            if (keycode == 13) {
                running = false;
                continue;
            }
            /* if (keycode != lastkeycode) {
                cout << (char)keycode;
            }*/ // debug
            lastkeycode = keycode;
        }
        onUpdate(keycode); // updating after the most important things

        onRender(); // rendering after most important render stuff
    }
    inputManager->closeInput(); // stopping the input thread and setting default terminal variables
    cout << endl;
    return exitcode;
}

void TerminalEngine::stop() {
    running = false;
}