#include <cstring>
#include <string>
#include <exception>
#include "Command.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <vector>
#include <stdlib.h>
using namespace std;

//Constructor
//Sotres the command in command
Command::Command(char* input){
    command = input;
}
//Execcutes the command
bool Command::execute(){
    string cppInput = command;
    string exitCommand = "exit";
    vector<char*> tempVector;
    
    //Removes extra whitespace at the beginning of the command
    string tempString = command;
    unsigned int tempStringLoc = 0;
    while(tempString.at(tempStringLoc) == ' '){
        tempString.erase(tempString.begin());
    }
    const char* tempConstString = tempString.c_str();
    command = strdup(tempConstString);
    
    //Sets cppInput to the string with removed whitespace
    cppInput = command;
    
    for (unsigned int i = 0; i < cppInput.length(); ++i) {
        //changes each character to lower case
        cppInput[i] = tolower(cppInput[i]);
    }
    //if == 0, then user wants to exit
    if (cppInput.compare(exitCommand) == 0) { 
        //throw the exception 
        string exitString = "Exiting";
        throw exitString;
        
    }
    //getting rid of the spaces inbetween
    for(char* parameters = strtok(command, " "); parameters != NULL; parameters = strtok(NULL, " ")){
        tempVector.push_back(parameters);
    }
    char* seperatedParameters[tempVector.size() + 1];
    unsigned int temp;
    for(temp = 0; temp < tempVector.size(); ++temp){
        seperatedParameters[temp] = tempVector.at(temp);
    }
    //null at the end to make life easier 
    seperatedParameters[tempVector.size()] = NULL;
    
    int status;
    pid_t pid = fork();
    //child
    if(pid == 0){
        //args: the first command entered, followed by the entire command
        execvp(seperatedParameters[0], seperatedParameters);
        exit(EXIT_FAILURE);
        cout << "Child process failed. " << endl;
    }
    //parent 
    else if(pid > 0){
        waitpid(-1, &status, 0);
        if(status == 0){
            return true;
        }
        else{
            return false;
        }
    }
    //if forking does not work
    else {
        cerr << "Error with forking process" << endl;
    }
    return false;
}
