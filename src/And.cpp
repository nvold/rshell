#include "Argument.h"
#include "And.h"

And::And(){
    leftChild = 0;
    rightChild = 0;
    left = false;
    right = false;
    connector = '&';
}
And::And(Argument* left_Child, Argument* right_Child){
    leftChild = left_Child;
    rightChild = right_Child;
    left = false;
    right = false;
    connector = '&';
}

//Runs the command in the left child. Changes left to true if it succeeds
//Runs the command in the right child if left is true. Changes right to true if it succeeds
//Returns true if left and right are true
bool And::execute(){
    left = leftChild->execute();
    if(left){
        right = rightChild->execute();
    }
    if(left && right){
        return true;
    }
    return false;
}

void And::setLeftChild(Argument* input){
    leftChild = input;
}
void And::setRightChild(Argument* input){
    rightChild = input;
}
char And::getConnector(){
    return connector;
}