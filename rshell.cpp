#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <exception>
#include "Argument.h"
#include "Or.h"
#include "And.h"
#include "Command.h"
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


int main(){
    string input;
    vector<char*> commands;
    vector<string> connectors;
    vector<Argument*> trees;
    while(1){
        cout << "$ ";
        getline(cin, input);
        commands = parse(input);
        connectors = findConnectors(input);
        trees = buildTrees(commands, connectors);
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