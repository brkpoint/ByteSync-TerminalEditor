#include "../incld.h"

#pragma once

// template<size_t... Indices> struct indices {};
// template<size_t N,size_t... Is> struct build_indices : build_indices<N-1, N-1, Is...> {};
// template<size_t... Is> struct build_indices<0, Is...> : indices<Is...> {};
// template <typename F, typename ArgTuple, size_t... Indices> auto call(F&& f, ArgTuple&& args, const indices<Indices...>&) -> decltype(f(get<Indices>(forward<ArgTuple>(args))...)) {
//    return move(f(get<Indices>(forward<ArgTuple>(args))...));
// }
// template <typename F, typename ArgTuple> auto call(F&& f, ArgTuple&& args) -> decltype(call(f, args, build_indices<tuple_size<ArgTuple>::value>{})) {
//     const build_indices<tuple_size<ArgTuple>::value> indices;
//     return move(call(f, move(args), indices));
// }

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
        virtual void execute() = 0; // executor
};

template<typename F, typename... Args> class Command : public CommandBase {
    private:
        function<void()> callback;
    public:
        // constructor
        Command(const string& command, const string& name, const string& desc, CommandType type, const F& func, Args&&... args) : CommandBase(command, name, desc, type) {
            callback = [func, args...](){
                func(args...);
            };
        }
        // executor from base
        void execute() override {
            callback();
        }
};

// command factory
template<typename F, typename... Args> CommandBase* CreateCommand(const string& command, const string& name, const string& desc, CommandType type, const F& func, Args&&... args) {
    return new Command<F, Args...>(command, name, desc, type, move(func), forward<Args>(args)...);
}
