#include "incld.h"
#include "Terminal/TerminalEngine.h"

void TerminalEngine::onUpdate(int keycode) {
    
}

void TerminalEngine::onRender() {
    //cout << "a\n"; /* test */
}

int main() {
    TerminalEngine* engine = new TerminalEngine();
    int exitcode = engine->start();

    delete engine;

    return exitcode;
}