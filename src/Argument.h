#ifndef ARGUMENT_H
#define ARGUMENT_H

//Abstract Base class
class Argument{
    public:
        Argument();
        virtual bool execute() = 0;
        virtual void setRightChild(Argument*) = 0;
        virtual void setLeftChild(Argument*) = 0;
        virtual char getConnector() = 0;
};

#endif