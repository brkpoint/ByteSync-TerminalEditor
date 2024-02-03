#include "incld.h"
#include "Terminal/TerminalEngine.h"

void TerminalEngine::onUpdate() {
    
}

void TerminalEngine::onRender() {
    cout << "a\n";
}

int main() {
    TerminalEngine* engine = new TerminalEngine();
    int exitcode = engine->start();

    delete engine;

    return exitcode;
}