#ifndef OR_H
#define OR_H

#include "Connector.h"

//Composite object
//Inherits from Argument
class Or : public Argument{
    private:
        char connector;
        Argument* leftChild;            //pointer to the left child
        Argument* rightChild;           //pointer to the right child
        bool left;                      //Set to true if the left child executed
        bool right;                     //Set to true if the right child executed
    public:
        Or();
        Or(Argument* left_child, Argument* right_child);    //Constructor
        bool execute();
        void setLeftChild(Argument*);
        void setRightChild(Argument*);
        char getConnector();
};

#endif