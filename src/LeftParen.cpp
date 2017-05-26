
#include "LeftParen.h"


LeftParen::LeftParen(){
    leftChild = 0;
    rightChild = 0;
    right = false;
    left = false;
    connector = '(';
    
}

void LeftParen::setLeftChild(Argument* object){
    return;
}
void LeftParen::setRightChild(Argument* object){
    return;
}

char LeftParen::getConnector()  {
    return '(';
}
 
bool LeftParen::execute() {
    return false;
}
