#include "Argument.h"
#include "Or.h"
//Constructor
Or::Or(){
}
Or::Or(Argument* left_Child, Argument* right_Child){
    leftChild = left_Child;
    rightChild = right_Child;
    left = false;
    right = false;
}

//Runs the command in LeftChild. Sets left to true if it runs successfully
//Runs the command in RightChild if left is false. Sets right to true if it runs succesfully
//Returns true if left or right are true
bool Or::execute(){
    left = leftChild->execute();
    if(!left){
        right = rightChild->execute();
    }
    if(left || right){
        return true;
    }
    return false;
}