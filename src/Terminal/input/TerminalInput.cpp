#include "TerminalInput.h";

static int keycode = -1;
static bool running = -1;

static void input_setter() {
    keycode = getchar();
}

static void input() {
    while (running) {
        thread inps(input_setter);
        inps.join();
    }
}

TerminalInput::TerminalInput() {
    system("stty raw");
}

TerminalInput::~TerminalInput() {

}

void TerminalInput::openInput() {
    running = true;
    inp = thread(input);
}

void TerminalInput::closeInput() {
    running = false;
    system("stty cooked");
}

int TerminalInput::readInput() {
    return keycode;
}
