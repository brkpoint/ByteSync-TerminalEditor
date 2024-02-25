#pragma once
#include "../utils/Vec.h"

class renderer {
    private:
        static char* framebufferFront[];
        static char* framebufferBack[];

        void renderFrame();
    public:
        int width, height;
        void update();
        void render();
        void printch(char c, Vec coords);
        void printstr(const char* c, Vec coord);
};