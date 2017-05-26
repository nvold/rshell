#ifndef LEFTPAREN_H
#define LEFTPAREN_H
#include "Connector.h"

class LeftParen : public Connector {
    private:
        char connector;
        Argument* leftChild;
        Argument* rightChild;
        bool right;
        bool left;
    
    public:
        LeftParen();
        void setLeftChild(Argument*);
        void setRightChild(Argument*);
        bool execute();
        char getConnector();
};
#endif