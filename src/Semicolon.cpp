#include "Connector.h"
#include "Semicolon.h"

Semicolon::Semicolon(){
    leftChild = 0;
    rightChild = 0;
    left = false;
    right = false;
    connector = ';';
}
void Semicolon::setLeftChild(Argument* input){
    return;
}
void Semicolon::setRightChild(Argument* input){
    return;
}
bool Semicolon::execute(){
    return false;
}
char Semicolon::getConnector(){
    return ';';
}