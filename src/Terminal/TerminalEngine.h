#include "../incld.h"

#pragma once

class TerminalEngine {
    private:
        bool running = true;
        int exitcode = 0;
        int keycode;

        void input();
    public:
        void setup();
        int start();

        virtual void onUpdate();
        virtual void onRender();
};