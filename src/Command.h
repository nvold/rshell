#ifndef COMMAND_H
#define COMMAND_H

#include "Argument.h"

//Leaf Object
//Inherits from Argument
class Command : public Argument{
    private:
        char* command;
    public:
        Command(char* input);
        bool execute(); //Runs the command. Returns true if it worked, false if it did not
};

#endif