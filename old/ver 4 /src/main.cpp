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

    pair<int, int> cursorxy = {0, 0};

    while (running) {
        terminal::getInfo();

        // resize detection

        if (terminal::sizeChanged()) {
            terminal::clear();
            {
                terminal::print(0, 0, f.fullname + " " + to_string(cursorxy.second) + ":" + to_string(cursorxy.first));
            }
            terminal::cursor(0, 1);
            continue;
        }

        // rendering
        
        // char proccessing

        char ch = getchar();

        switch (ch) {
            case -1:
                break;
            case 'q':
                running = false;
                terminal::clear();
                break;
            /* arrows */
            case 27:
                getchar();
                switch(getchar()) {
                    case 65: // up
                        cursorxy.second--;
                        terminal::print(0, 0, f.fullname + " " + to_string(cursorxy.second) + ":" + to_string(cursorxy.first));
                        cout << "\x1b[A";
                        break;
                    case 66: // down
                        cursorxy.second++;
                        terminal::print(0, 0, f.fullname + " " + to_string(cursorxy.second) + ":" + to_string(cursorxy.first));
                        cout << "\x1b[B";
                        break;
                    case 67: // right
                        cursorxy.first++;
                        terminal::print(0, 0, f.fullname + " " + to_string(cursorxy.second) + ":" + to_string(cursorxy.first));
                        cout << "\x1b[C";
                        break;
                    case 68: // left
                        cursorxy.first--;
                        terminal::print(0, 0, f.fullname + " " + to_string(cursorxy.second) + ":" + to_string(cursorxy.first));
                        cout << "\x1b[D";
                        break;
                }
                break;
            /* char stuff */
            case 13: // enter

                break;
            case 127: // remove char

                break;
            /* other chars */
            default:
                terminal::print(0, 0, f.fullname + " " + to_string(cursorxy.second) + ":" + to_string(cursorxy.first));
                terminal::print(0, 1, to_string((int)ch) + " ");
                break;
        }
    }

    input::inpend();

    system("clear");
    
    return 0;
}
