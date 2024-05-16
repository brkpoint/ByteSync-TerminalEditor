#include "incld.h"
#include "Terminal/InputManager.h"

using namespace Terminal;

int main(int argc, char** argv) {
    // no files in args
    if (argc <= 1) {
        cout << "No file specified, exiting." << endl;
        return 0;
    }

    bool running = true;

    TerminalData data = GetData(); // getting the terminal data
    InputManager inpMgr = InputManager(data);

    system("clear");

    // program loop
    while (running) {
        char c = getchar(); // getting the char
        running = inpMgr.Update(c); // updating and getting the output
    }
    
    return 0;
}
