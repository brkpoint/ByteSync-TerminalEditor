#include "../incld.h"
#include "../utils/str.cpp"
#include "Terminal.h"
#include "Command.h"

#pragma once

enum Keycodes {
    RETURN = 13,
    BACKSPACE = 127,
    SHIFT = 16,
    CAPSLOCK = 20,
    TAB = 9,
    ALT = 18, // mac option key or windows alt
    META = 91, // mac command key
    ESCAPE = 53,
    ARR_CODE = 27,
    ARR_LEFT = 68,
    ARR_UP = 65,
    ARR_DOWN = 66,
    ARR_RIGHT = 67,
};

enum InputModes {
    CONTROL_MODE = 0,
    INSERT_MODE = 1,
};

class InputManager {
    private:
        TerminalData terminalData; // data

        bool running = true; // program running

        int editState = 0; // states for editor
        //      CONTROL MODE      // //       INSERT MODE        //
        // - controlling windows  // // - editing current file   //
        // - cant through lines   // // - cannot enter commands  //
        // - entering commands    // // - cannot control windows //
        // - cannot edit file     // // - can move lines         //

        string currentLine; // current input

        void RunCommand(string str); // proccessing commands

        void ProccessMovement(int arrowCode); // movement
        void ProccessEdit(int ch); // input

        // void ProccessWindowing(); // for later
    public:
        // commands
        vector<CommandBase*> commands; // for interacting with the app
                                       // for replacing text etc.

        InputManager(TerminalData data);
        ~InputManager();

        bool Update(int ch);
};
