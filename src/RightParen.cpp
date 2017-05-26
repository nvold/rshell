
#include "RightParen.h"


RightParen::RightParen(){
    leftChild = 0;
    rightChild = 0;
    left = false;
    right = false;
    connector = ')';
}

void RightParen::setLeftChild(Argument* object){
    return;
}
void RightParen::setRightChild(Argument* object){
    return;
}
bool RightParen::execute(){
    return false;
}
char RightParen::getConnector(){
    return ')';
}