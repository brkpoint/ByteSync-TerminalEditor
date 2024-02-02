#include <iostream>
#include <stdint.h>

#include "vars/vars.h"
#include "rendering/renderer.h"

using namespace std;

renderer render;

void getInput() {
    system("stty raw");
    g_vars.c = getchar(); 
    system("stty cooked");

    if(g_vars.c == 13) {
        system("stty cooked");
        g_vars.running = false;
        g_vars.exitCode = 0;
    }
}

void update() {
    getInput();
    render.update();
}

int main() {
    while(g_vars.running) {
        update();
        render.render();
    }

    printf("\n");

    return g_vars.exitCode;
}
