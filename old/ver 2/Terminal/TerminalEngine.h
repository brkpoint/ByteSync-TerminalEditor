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

        // those are frame buffers, we can wait for back buffer to finish drawing and swap those aka double buffering (to avoid flashes and screen tearing)
        vector<string> frontbuffer; // current frame
        vector<string> backbuffer; // next frame
        
        TerminalInput* inputManager;

        void draw();
    public:
        TerminalEngine();
        ~TerminalEngine();

        int start();
        void stop();

        void clear();
        void print(char ch);
        void print(const char* str);
        void print(string str);

        virtual void onStart();
        virtual void onUpdate(int keycode);
        virtual void onRender();
};