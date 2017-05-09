#ifndef CONNECTOR_H
#define CONNECTOR_H
#include "Argument.h"

//Abstract base class for the connector classes
//Inherits from Argument
class Connector: public Argument{
    private:
        Argument* leftChild;            //pointer to the left child
        Argument* rightChild;           //pointer to the right child
        bool left;                      //Set to true if the left child executed
        bool right;                     //Set to true if the right child executed
    public:
        Connector();                    //Constructor
        virtual bool execute() = 0;
};

#endif