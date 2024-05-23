#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

#include "./file/file.h"
#include "./terminal/input.h"
#include "./terminal/terminal.h"
#include "./terminal/color.h"

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

    

    string input = "";

    while (running) {
        terminal::getInfo();
        
        char ch = getchar();
        if (ch == 'q') {
            running = false;
            break;
        }

        if (terminal::sizeChanged()) {
            terminal::clear();
            continue;
        }

        if (ch != -1) {
            input += ch;
        }

        

        terminal::print(0, 1, input);
        terminal::render();

        usleep(1000);
    }

    input::inpend();

    system("clear");
    
    return 0;
}
