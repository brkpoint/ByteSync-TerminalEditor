#include "renderer.h"
#include <iostream>
#include <stdint.h>

#include "../vars/vars.h"

void copy(char* dst[], char* origin[], int length) {
    for (int i = 0; i < length; i++) strcpy(dst[i], origin[i]);
}

void renderer::renderFrame() {
    system("clear");
    printch(g_vars.c, Vec(0, 0));
}

void renderer::update() {

}

void renderer::render() {
    renderFrame();
    char* copyFront[] = {};
    copy(copyFront, framebufferFront, height);
    copy(framebufferFront, framebufferBack, height);
    copy(framebufferBack, copyFront, height);
    for (int i = 0; i < height; i++)
        printf("%s", framebufferFront[i]);
}

void renderer::printch(char c, Vec coord) {
    framebufferBack[coord.y][coord.x] = c;
}

void renderer::printstr(const char* c, Vec coord) {
    for (int i = 0; i < *(&c + 1) - c; i++) // test this
        printch(c[i], Vec(coord.x + i, coord.y));
}