#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H
#include "Connector.h"

class RightParen : public Connector {
    private:
        char connector;
        Argument* rightChild;
        Argument* leftChild;
        bool left;
        bool right;
    
    public:
        RightParen();
        void setLeftChild(Argument*);
        void setRightChild(Argument*);
        bool execute();
        char getConnector();
}; 
#endif