#include "TerminalEngine.h"

void TerminalEngine::setup() {
    system("clear");
    cout << "hello\n";
}

int TerminalEngine::start() {
    while(running) {

        input();
        onUpdate();

        onRender();
    }
    cout << endl;
    return exitcode;
}

int TerminalEngine::inputThread() {
    return 0;
}

void TerminalEngine::input() {
    future<int> future = async(launch::async, inputThread);
    keycode = future.get();
}