#include "../incld.h"
#include "input/TerminalInput.h"
#include "utils/color.cpp"

#pragma once

class TerminalEngine {
    private:
        bool running;
        int exitcode;

        int widthCH;
        int heightCH;

        int height;
        int width;
        
        TerminalInput* inputManager;
    public:
        TerminalEngine();
        ~TerminalEngine();

        int start();
        void stop();

        void print(char ch);
        void print(const char* str);
        void print(string str);

        virtual void onStart();
        virtual void onUpdate(int keycode);
        virtual void onRender();
};