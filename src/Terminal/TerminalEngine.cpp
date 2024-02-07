#include "TerminalEngine.h"

static int keycode = -1;
static int lastkeycode = -1;

vector<vector<string>> tempbuffer;

TerminalEngine::TerminalEngine() {
    inputManager = new TerminalInput();

    // getting the height and width of the terminal in pixles and chars
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    widthCH = w.ws_row; // char width
    heightCH = w.ws_col; // char height

    width = w.ws_xpixel; // normal width
    height = w.ws_ypixel; // normal height

    // oof code (needs a fix)
    string empty;
    for (int w = 0; w < widthCH - 1; w++) empty += ' ';

    // initializing a front and back buffers
    for (int h = 0; h < heightCH - 1; h++) { 
        frontbuffer.push_back(empty);
        backbuffer.push_back(empty);
    }

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

void TerminalEngine::draw() {
    for (int h = 0; h < heightCH - 1; h++)
        cout << frontbuffer.at(h) << endl;
}

void TerminalEngine::clear() {
    for (int h = 0; h < heightCH - 1; h++)
        for (int w = 0; w < widthCH - 1; w++)
            backbuffer.at(h).at(w) = ' ';

    inputManager->cursorMove(0, 0);
}

void TerminalEngine::print(char ch) {

}

void TerminalEngine::print(const char* str) {

}

void TerminalEngine::print(string str) {

}

int TerminalEngine::start() {
    inputManager->openInput(); // creating a new thread and setting input terminal variables
    onStart(); // call the virtual start
    while(running) {
        // input
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

        // drawing
        {
            clear();
        }
        onRender(); // rendering after most important render stuff
        frontbuffer = backbuffer; // swaping buffers (kinda, we dont need the backbuffer to be swaped because we are gonna clear it anyways)
        draw();
    }
    clear(); // clearing the terminal
    inputManager->closeInput(); // stopping the input thread and setting default terminal variables
    cout << endl;
    return exitcode;
}

void TerminalEngine::stop() {
    running = false;
}