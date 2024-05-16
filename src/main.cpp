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

    system("clear");

    string contents;
    file f = file(argv[1]);
    int code = f.getFileContents(contents);

    if (code) return 0;

    input::inpinit();

    bool running = true;

    while (running) {
        terminal::getInfo();
        
        if (getchar() == 'q') running = false;
        if (terminal::sizeChanged()) {

            continue;
        }

        

        usleep(10000);
    }

    input::inpend();
    
    return 0;
}
