#pragma once

struct vars {
    bool running = true;

    int exitCode = 0;

    char c;
    char* lastInput;
};

extern vars g_vars;
