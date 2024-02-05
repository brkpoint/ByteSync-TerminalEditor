#include "../../incld.h"

#pragma once

class TerminalInput {
    private:
        thread inp;
    public:
        TerminalInput();
        ~TerminalInput();

        void openInput();
        void closeInput();

        bool isInputAvaiable();
        int readInput();
};