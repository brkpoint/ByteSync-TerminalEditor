#include "TerminalInput.h"

static int keycode = -1;
atomic<bool> running;
atomic<bool> should_close(false);

static void input_setter() {
    keycode = getchar(); // setting the keycode to the input
}

static void input() {
    thread inps;
    while (running.load()) {
        inps = thread(input_setter); // assigining a new thread
        inps.join(); // waiting and then assigining the keycode
    }
}

void TerminalInput::update_cursor() {
    printf("%c[%d;%df", 0x1b, cursor.x, cursor.y); // setting the cursor pos
}

TerminalInput::TerminalInput() {
    system("stty raw"); // setting the terminal to send raw input
}

TerminalInput::~TerminalInput() {
    closeInput();
}

void TerminalInput::openInput() {
    update_cursor();
    running.store(true);
    inp = thread(input); // creating new input thread
}

void TerminalInput::closeInput() {
    running.store(false);
    // freeing thread
    pthread_kill(inp.native_handle(), 0);
    delete &inp;
    // freeing variables
    delete &running;
    delete &keycode;
    cursorMove(0, 0); // reseting the cursor pos
    system("stty cooked"); // setting the terminal to send processed input
}

void TerminalInput::cursorMove(int x, int y) {
    cursor.x = x; // setting the x pos
    cursor.y = y; // setting the y pos
    update_cursor(); // updating
}

vec2 TerminalInput::getCursorPos() {
    return cursor;
}

int TerminalInput::readInput() {
    return keycode;
}
