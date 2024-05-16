#include "../incld.h"

#pragma once

// commands type
enum CommandType {
    ND = -1, // not defined type
    ACTION_COMMAND = 0,
    EDIT_COMMAND = 1,
};

/// command base class for oop
class CommandBase {
    protected:
        string command; // command
        string name; // name of the command (for help command)
        string desc; // description (also for the help command)
        CommandType type; // command type for grouping
    public:
        CommandBase(const string& command, const string& name, const string& desc, CommandType type) : command(command), name(name), desc(desc), type(type) {} // constuctor
        const string GetCommand() { return command; } // command string getter
        const string GetName() { return name; } // command name getter
        const string GetDesc() { return desc; } // command description getter
        const CommandType GetType() { return type; } // command type getter

        virtual ~CommandBase() {} // (deconstructor if someone didnt know)
        virtual void execute(vector<string> args) = 0; // executor
};

template<typename F, typename... Args> class Command : public CommandBase {
    private:
        function<void(vector<string>&&)> callback;
    public:
        // constructor
        Command(const string& command, const string& name, const string& desc, CommandType type, const F& func, Args&&... args) : CommandBase(command, name, desc, type) {
            callback = [func, args...](vector<string>&& argsCMDL){
                func(argsCMDL, args...);
            };
        }
        // executor from base
        void execute(vector<string> args) override {
            callback(forward<vector<string>>(args)); // invoking the callback function with arguments from the user
        }
};

// command factory
template<typename F, typename... Args> CommandBase* CreateCommand(const string& command, const string& name, const string& desc, CommandType type, const F& func, Args&&... args) {
    return new Command<F, Args...>(command, name, desc, type, move(func), forward<Args>(args)...);
}
