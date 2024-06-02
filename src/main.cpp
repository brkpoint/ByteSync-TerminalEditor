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

    string inp = "";

    int posx = 0;
    int posy = 0;

    while (running) {
        terminal::getInfo();

        // resize detection

        if (terminal::sizeChanged()) {
            terminal::clear();
            {
                terminal::print(0, 0, f.fullname + " " + to_string(posy) + ":" + to_string(posx));
            }
            terminal::cursor(0, 1);
            continue;
        }

        // rendering

        terminal::print(0, 0, f.fullname + " " + to_string(posy) + ":" + to_string(posx));
        
        // char proccessing

        char ch = getchar();

        switch (ch) {
            case -1:
                break;
            case 'q':
                running = false;
                terminal::clear();
                break;
            default:
                //terminal::print(0, 1, to_string((int)ch) + " ");
                //cout << ch;
                //posx++;
                break;
        }
    }

    input::inpend();

    system("clear");
    
    return 0;
}
