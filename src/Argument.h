#ifndef ARGUMENT_H
#define ARGUMENT_H

//Abstract Base class
class Argument{
    public:
        Argument();
        virtual bool execute() = 0;
};

#endif