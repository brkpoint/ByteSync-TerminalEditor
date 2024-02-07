#include "incld.h"
#include "Terminal/TerminalEngine.h"

void TerminalEngine::onStart() {

}

void TerminalEngine::onUpdate(int keycode) {
    
}

void TerminalEngine::onRender() {
    print("hello\n");
}

int main() {
    TerminalEngine* engine = new TerminalEngine();
    int exitcode = engine->start(); // starting the terminal window, and after it stopped working getting the stop code
    delete engine;

    return exitcode;
}