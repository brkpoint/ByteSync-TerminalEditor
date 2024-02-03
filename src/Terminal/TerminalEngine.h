#include "../incld.h"
#include "input/TerminalInput.h"

#pragma once

class TerminalEngine {
    private:
        bool running;
        int exitcode;
        
        TerminalInput* inputManager;
    public:
        TerminalEngine();
        ~TerminalEngine();

        int start();

        virtual void onUpdate();
        virtual void onRender();
};