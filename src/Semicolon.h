#ifndef SEMICOLON_H
#define SEMIMCOLON_H

#include "Connector.h"

class Semicolon : public Connector {
    private:
        char connector;
        Argument* leftChild;
        Argument* rightChild;
        bool left;
        bool right;
    public:
        Semicolon();
        void setLeftChild(Argument*);
        void setRightChild(Argument*);
        bool execute();
        char getConnector();
};

#endif