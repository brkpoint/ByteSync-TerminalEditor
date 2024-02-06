#pragma once

// simple vector 2
class vec2 {
    public:
        int x, y; // coords
        vec2() = default; // default constructor
        vec2(int xc, int yc) {
            x = xc;
            y = yc;
        }
};
