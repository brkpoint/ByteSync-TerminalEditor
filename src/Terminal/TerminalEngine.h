#include "../incld.h"
#include "input/TerminalInput.h"
#include "utils/color.cpp"

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
        void stop();

        virtual void onStart();
        virtual void onUpdate(int keycode);
        virtual void onRender();
};