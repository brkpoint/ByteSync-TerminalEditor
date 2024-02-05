#include "TerminalInput.h"

static int keycode = -1;
static bool running = false;

static void input_setter() {
    keycode = getchar(); // setting the keycode to the input
}

static void input() {
    thread inps;
    while (running) {
        inps = thread(input_setter); // assigining a new thread
        inps.join(); // waiting and then assigining the keycode
    }
}

TerminalInput::TerminalInput() {
    system("stty raw"); // setting the terminal to send raw input
}

TerminalInput::~TerminalInput() {
    closeInput();
}

void TerminalInput::openInput() {
    running = true;
    inp = thread(input); // creating new input thread
}

void TerminalInput::closeInput() {
    running = false;
    inp.~thread();
    delete &running;
    delete &keycode;
    system("stty cooked"); // setting the terminal to send processed input
}

int TerminalInput::readInput() {
    return keycode;
}
