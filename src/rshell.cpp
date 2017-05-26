#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <exception>
#include "Argument.h"
#include "Or.h"
#include "And.h"
#include "Command.h"
#include "RightParen.h"
#include "LeftParen.h"
#include "Semicolon.h"
// Neesha Bhardwaj 
// Nicholas Volden

using namespace std;

vector<char*> parse(string input){
    //stores the commands
    vector<char*> commandVector;
    
    //converts the string to a c string
    const char* constCInput = input.c_str();
    
    //converts the char* to a non const
    char* cInput = strdup(constCInput);
    
    //Seperates the string into the indivual commands using the strtok function
    for(char* parsedString = strtok(cInput, ";&|#"); parsedString != NULL; parsedString = strtok(NULL, ";&|#")){
        commandVector.push_back(parsedString);
    }
    return commandVector;
}

//stores the connectors in a vector in the correct order
vector<string> findConnectors(string input){
    //stores connectors
    vector<string> connectors;
    
    //searches for connectors in input, and pushes them into connectors
    for(unsigned int i = 0; i < input.length(); ++i){
        char curr = input.at(i);
        if(curr == ';'){
            connectors.push_back(";");
        }
        else if(curr == '#'){
            connectors.push_back("#");
        }
        else if(i + 1 < input.length()){
            char next = input.at(i + 1);
            if(curr == '&'){
                if(next == '&'){
                    connectors.push_back("&&");
               } 
            }
            else if(curr == '|'){
                if(next == '|'){
                    connectors.push_back("||");
                }
            }
        }
    }
    return connectors;
}

//creates the trees of commands and connectors, and stores them in a vector
vector<Argument*> buildTrees(vector<char*> commands, vector<string> connectors){
    //Stores the constructed trees
    vector<Argument*> tree;
    
    //Top part of the tree
    Argument* parent;
    
    //set to 1 if a comment symobol is found
    unsigned int commentFlag = 0;
    
    //Stores the amount of connectors created
    unsigned int commandCnt = 0;
    
    //Makes sure the command vector is not empty
    if(commands.size() > 0){
        
        Argument* newCommand = new Command(commands.at(0));
        parent = newCommand;
        commandCnt = 1;
        for(unsigned int i = 0; i < connectors.size(); ++i){
            if(connectors.at(i) == ";" && commentFlag == 0){
                tree.push_back(parent);
                newCommand = new Command(commands.at(commandCnt));
                parent = newCommand;
                commandCnt++;
            }
            else if(connectors.at(i) == "#" && commentFlag == 0){
                commentFlag = 1;
            }
            else if(commentFlag == 0){
                Argument* nextCommand = new Command(commands.at(commandCnt));
                commandCnt++;
                if(connectors.at(i) == "&&"){
                    Argument* newConnector = new And(parent, nextCommand);
                    parent = newConnector;
                }
                else if(connectors.at(i) == "||"){
                    Argument* newConnector = new Or(parent, nextCommand);
                    parent = newConnector;
                }
            }
        }
        tree.push_back(parent);
    }
    return tree;
}

//Parses entered commands containing presedence operators
//Searches for connectors, then makes command and connector objects
//The created objects are then pushed into the vector parsedInput, which is returned
vector<Argument*> parenthesesParse(string input){
    unsigned int startIndex = 0;
    unsigned int length;
    vector<Argument*> parsedInput;
    for(unsigned int endIndex = 0; endIndex < input.length(); endIndex++){
        if(input.at(endIndex) == ';'){
            if(startIndex == endIndex){
                parsedInput.push_back(new Semicolon());
            }
            else{
                length = endIndex - startIndex - 1;
                string temp = input.substr(startIndex + 1, length);
                const char* tempConst = temp.c_str();
                char* tempC = strdup(tempConst);
                parsedInput.push_back(new Command(tempC));
                parsedInput.push_back(new Semicolon());
                if(endIndex != input.length() - 1){
                    startIndex = endIndex + 1;
                }
            }
        }
        else if(input.at(endIndex) == '&'){
            if(startIndex == endIndex || startIndex == endIndex - 1){
                parsedInput.push_back(new And());
                endIndex++;
                startIndex += 2;
            }
            else{
                length = endIndex - startIndex - 1;
                string temp = input.substr(startIndex + 1, length);
                const char* tempConst = temp.c_str();
                char* tempC = strdup(tempConst);
                parsedInput.push_back(new Command(tempC));
                parsedInput.push_back(new And());
                endIndex++;
                startIndex = endIndex + 1;
            }
        }
        else if(input.at(endIndex) == '|'){
            if(startIndex == endIndex || startIndex == endIndex - 1){
                parsedInput.push_back(new Or());
                endIndex++;
                startIndex += 2;
            }
            else{
                length = endIndex - startIndex - 1;
                string temp = input.substr(startIndex + 1, length);
                const char* tempConst = temp.c_str();
                char* tempC = strdup(tempConst);
                parsedInput.push_back(new Command(tempC));
                parsedInput.push_back(new Or());
                endIndex++;
                startIndex = endIndex + 1;
            }
        }
        else if(input.at(endIndex) == '('){
            if(startIndex == endIndex || startIndex > endIndex - 3){
                parsedInput.push_back(new LeftParen());
                startIndex = endIndex ;
            }
            else{
                length = endIndex - startIndex - 1;
                string temp = input.substr(startIndex + 1, length);
                const char* tempConst = temp.c_str();
                char* tempC = strdup(tempConst);
                parsedInput.push_back(new Command(tempC));
                parsedInput.push_back(new LeftParen());
                //endIndex++;
                startIndex++;
            }
        }
        else if(input.at(endIndex) == ')'){
            if(startIndex == endIndex){
                parsedInput.push_back(new RightParen());
                startIndex = endIndex + 1;
            }
            else{
                length = endIndex - startIndex - 1;
                string temp = input.substr(startIndex + 1, length);
                const char* tempConst = temp.c_str();
                char* tempC = strdup(tempConst);
                parsedInput.push_back(new Command(tempC));
                parsedInput.push_back(new RightParen());
                startIndex = endIndex + 1;
            }
        }
        else if(input.at(endIndex) == '#'){
            if(startIndex == endIndex || startIndex == endIndex - 1){
                endIndex = input.length() - 1;
                startIndex = endIndex;
            }
            else{
                length = endIndex - startIndex - 1;
                string temp = input.substr(startIndex + 1, length);
                const char* tempConst = temp.c_str();
                char* tempC = strdup(tempConst);
                parsedInput.push_back(new Command(tempC));
                endIndex = input.length() - 1;
                startIndex = endIndex + 1;
            }
        }
    }
    if(startIndex < (input.size() - 1)){
        length = (input.size() - 1) - startIndex - 1;
        string temp = input.substr(startIndex + 1, length + 1);
        const char* tempConst = temp.c_str();
        char* tempC = strdup(tempConst);
        parsedInput.push_back(new Command(tempC));
    }
    return parsedInput;
}

//Returns the amount of semicolons in the entered command
unsigned int semicolonCnt(string input){
    unsigned int cnt = 0;
    for(unsigned int i = 0; i < input.length(); ++i){
        if(input.at(i) == ';'){
            cnt++;
        }
    }
    return cnt;
}

Argument* buildSubTree(vector<Argument*> subVector){
    vector<Argument*> tree = subVector;
    if(tree.size() == 1){
        return tree.at(0);
    }
    Argument* parent = tree.at(1);
    parent->setLeftChild(tree.at(0));
    parent->setRightChild(tree.at(2));
    unsigned int i = 3;
    while(i < tree.size()){
        tree.at(i)->setLeftChild(parent);
        tree.at(i)->setRightChild(tree.at(i + 1));
        parent = tree.at(i);
        i += 2;
    }
    return parent;
}

vector<Argument*> parenthesesTree(string input){
    vector<Argument*> tree = parenthesesParse(input);
    //Pointer to the top of the tree
    unsigned int finalSize = semicolonCnt(input) + 1;

    while(tree.size() > finalSize){
        unsigned int startIndex = 0;
        unsigned int endIndex = 0;
        int leftParenthesesFlag = 0;
        int rightParenthesesFlag = 0;
        
        //finds the first close parentheses, sets endIndex equal to its position
        for(unsigned int i = 0; i < tree.size(); ++i){
            if(tree.at(i)->getConnector() == ')'){
                rightParenthesesFlag = 1;
            }
            if(rightParenthesesFlag == 0){
                endIndex++;
            }
        }
        if(rightParenthesesFlag == 0){
            vector<Argument*> temp;
            temp.push_back(buildSubTree(tree));
            return temp;
        }
        startIndex = endIndex;
        //finds the open parentheses for the parentheses at endIndex
       for (int i = endIndex; i >= 0; --i) {
           if (tree.at(i)->getConnector() == '(' ){
               leftParenthesesFlag = 1;
           }
           if (leftParenthesesFlag == 0){
               startIndex--;
           }
        }
        vector<Argument*> tempVec;
        for(unsigned int i = startIndex + 1; i < endIndex; ++i){
            tempVec.push_back(tree.at(i));
        }
        tree.erase(tree.begin() + startIndex, tree.begin() + endIndex + 1);
        if(tree.empty()){
            tree.push_back(buildSubTree(tempVec));
        }
        else{
            tree.insert(tree.begin() + startIndex, buildSubTree(tempVec));
        }
    }
    
    return tree;
}



int main(){
    string input;
    vector<char*> commands;
    vector<string> connectors;
    vector<Argument*> trees;
    while(1){
        cout << "$ ";
        getline(cin, input);
        
        //Checks for parentheses
        int leftParenCnt = 0;
        int rightParenCnt = 0;
        for(unsigned int i = 0; i < input.length(); ++i){
            if(input.at(i) == '('){
                ++leftParenCnt;
            }
            else if(input.at(i) == ')'){
                ++rightParenCnt;
            }
        }
        if(leftParenCnt > 0 || rightParenCnt > 0){
            if(leftParenCnt != rightParenCnt){
                //error
            }
            //seperate parsing function for commands with parentheses 
            else{
                trees = parenthesesTree(input);
            }
        }
        else{
            commands = parse(input);
            connectors = findConnectors(input);
            trees = buildTrees(commands, connectors);
        }
        try{
            for(unsigned int i = 0; i < trees.size(); ++i){
                trees.at(i)->execute();
            }
        }
        catch(string exitCalled){
            cout << exitCalled << endl;
            return 0;
        }
    }
    
    return 0;
}