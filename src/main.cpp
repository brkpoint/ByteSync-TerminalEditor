#include <iostream>
#include <fstream>
#include <string>

#include "./file/file.h"
#include "./terminal/input.h"
#include "./terminal/terminal.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "No file specified, exiting." << endl;
        return 0;
    }

    string contents;
    file f = file(argv[1]);
    int code = f.getFileContents(contents);

    if (code) return 0;

    terminal::clear();

    input::inpinit();

    bool running = true;

    while (running) {
        char ch;

        terminal::getInfo();
        
        ch = getchar();
        if (ch == 'q') {
            running = false;
            break;
        }

        if (terminal::sizeChanged()) continue;

        if (ch != -1) cout << ch;

        usleep(10000);
    }

    input::inpend();

    system("clear");
    
    return 0;
}
