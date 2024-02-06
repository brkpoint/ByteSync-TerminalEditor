#include "../../incld.h"

#pragma once

class TerminalInput {
    private:
        vec2 cursor = vec2(20, 20);

        thread inp;

        void update_cursor();
    public:
        TerminalInput();
        ~TerminalInput();

        void openInput();
        void closeInput();

        void cursorMove(int x, int y);
        vec2 getCursorPos();

        int readInput();
};