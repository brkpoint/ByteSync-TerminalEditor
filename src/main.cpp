#include "incld.h"
#include "Terminal/TerminalEngine.h"

void TerminalEngine::onUpdate() {
    
}

void TerminalEngine::onRender() {

}

int main() {
    TerminalEngine engine;

    engine.setup();
    int exitcode = engine.start();

    return exitcode;
}