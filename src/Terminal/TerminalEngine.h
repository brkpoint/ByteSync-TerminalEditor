#include "../incld.h"

#pragma once

class TerminalEngine {
    private:
        bool running = true;
        int exitcode = 0;
        int keycode;

        static int inputThread();
        void input();
    public:
        void setup();
        int start();

        virtual void onUpdate();
        virtual void onRender();
};