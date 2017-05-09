#include "Argument.h"
#include "And.h"

And::And(){
}
And::And(Argument* left_Child, Argument* right_Child){
    leftChild = left_Child;
    rightChild = right_Child;
    left = false;
    right = false;
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