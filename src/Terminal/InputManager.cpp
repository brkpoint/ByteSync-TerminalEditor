#include "InputManager.h"

InputManager::InputManager(TerminalData data) {
    system("stty raw"); // get raw input from terminal

    commands.push_back(
        CreateCommand("q", "quit", "Quits the application.", ACTION_COMMAND,
            [](vector<string> args, bool* running) {
                *running = false;
            }, &running
        )
    );
    commands.push_back(
        CreateCommand("h", "help", "Shows all avaiable commands.", ACTION_COMMAND,
            [](vector<string> args, vector<CommandBase*> cmds) {
                for (CommandBase* command : cmds) {
                    cout << "h "
                        << "help "
                        << "Shows all avaiable commands." << endl;

                    cout << command->GetCommand() << " "
                        << command->GetName() << " "
                        << command->GetDesc() << endl;
                }
            }, commands
        )
    );

    terminalData = data;
}

InputManager::~InputManager() {
    system("stty cooked"); // reseting
    commands.clear(); // cleaning commands (to prevent memory leaks ig...)
}

void InputManager::RunCommand(string str) {
    CommandType type = ND;
    string commandName;
    vector<string> args;
    if (str.rfind(":", 0) == 0) { // action commands
        str.erase(str.begin()); // removing the prefix
        args = split(str, ' '); // removing all spaces
        commandName = args.at(0);
        args.erase(next(args.begin(), 0));
        type = ACTION_COMMAND; // setting the type of the command
    }

    if (type == ND) return; // if no type set then return (not found)

    // iterating for every command
    for (CommandBase* cmd : commands) {
        if (cmd->GetType() != type) continue; // if it isnt the type just skip
        if (cmd->GetCommand() == commandName && cmd->GetType() == type) {
            cmd->execute(args); // executing
            return;
        }
    }
}

void InputManager::ProccessEdit(int ch) {

}

void InputManager::ProccessMovement(int arrowCode) {

}

bool InputManager::Update(int ch) {
    switch (ch) {
    case RETURN:
        if (editState == CONTROL_MODE) {
            system("clear");
            RunCommand(currentLine); // running the command
            currentLine = ""; // clearing the line
            break;
        }
        
        system("clear");
        currentLine = ""; // clearing the line
        break;
    case TAB:
        if (editState == CONTROL_MODE) break;
        //currentLine = concat(currentLine, "    ");
        break;
    case BACKSPACE:
        if (currentLine.empty()) break;
        currentLine.pop_back();
        system("clear");
        cout << currentLine;
        break;
    case CAPSLOCK:
        break;
    case META:
        break;
    case ALT:
        break;
    case SHIFT:
        break;
    case ESCAPE:
        if (editState != INSERT_MODE) break;
        editState = 0;
        break;
    case ARR_CODE: // if those are arrows
        getchar(); // skipping one char
        switch (getchar()) { // getting the arrow char
        case ARR_LEFT:
            ProccessMovement(ARR_LEFT); // left
            break;
        case ARR_UP:
            ProccessMovement(ARR_UP); // up
            break;
        case ARR_DOWN:
            ProccessMovement(ARR_DOWN); // down
            break;
        case ARR_RIGHT:
            ProccessMovement(ARR_RIGHT); // right
            break;
        }
        break;
    default:
        // cout << ch; // for debuging
        currentLine += ch; // adding the char
        system("clear");
        cout << currentLine; // printing
        break;
    }

    return running;
}
