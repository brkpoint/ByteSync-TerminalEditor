#include "../../incld.h"

#pragma once

class TerminalInput {
    private:

    public:
        TerminalInput();
        ~TerminalInput();

        void openInput();
        void closeInput();

        bool isInputAvaiable();
        int readInput();
};