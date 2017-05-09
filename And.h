#ifndef AND_H
#define AND_H
#include <iostream>
#include "Connector.h"

//Composite object
//Inherits from Argument
class And : public Argument{
    private:
        Argument* leftChild;            //pointer to the left child
        Argument* rightChild;           //pointer to the right child
        bool left;                      //Set to true if the left child executed
        bool right;                     //Set to true if the right child executed
    public:
        And();
        And(Argument* left_child, Argument* right_child);
        bool execute();
};

#endif