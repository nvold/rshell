#include <cstring>
#include <string>
#include <exception>
#include "Command.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <stdlib.h>
using namespace std;

//runs the test command, returning 0 if the file/directory exists, returning  otherwise
int testCommand(char* testCommand){
    //seperates the flag and the path into seperate char*
    char* flag = strtok(NULL, " ");
    char* path = strtok(NULL, " ");
    //stores the flag in a string for comparison
    string cppFlag = flag;
    
    struct stat locInfo;
    //checks if the path exists
    if(!stat(path, &locInfo)){
        //returns 0 if the location is a directory, 1 if it is not
        if(S_ISREG(locInfo.st_mode)){
            if(cppFlag == "-e" || cppFlag == "-f"){
                return 0;
            }
            return 1;
        }
        //returns 0 if the location is a file, 1 if it is not
        else if(S_ISDIR(locInfo.st_mode)){
            if(cppFlag == "-e" || cppFlag == "-d"){
                return 0;
            }
            return 1;
        }
        return 0;
    }
    return 1;
}



//Constructor
//Stores the command in command
Command::Command(char* input){
    command = input;
}
//Execcutes the command
bool Command::execute(){
    string cppInput = command;
    string exitCommand = "exit";
    vector<char*> tempVector;
    
    //Checks to see if the command is a test command, calls testCommand if it is
    char* testCheck = strdup(command);
    char* firstString = strtok(testCheck, " ");
    string checkTest = firstString;
    if(checkTest.compare("test") == 0 || checkTest.compare("[") == 0){
        int result = testCommand(command);
        if(result == 0){
            cout << "(true)" << endl;
            return true;
        }
        else if(result == 1){
            cout <<"(false)" << endl;
            return true;
        }
        return false;
    }
    
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
    
    char** seperatedParameters = new char*[tempVector.size() + 1];
    for(unsigned int temp = 0; temp < tempVector.size(); ++temp){
        seperatedParameters[temp] = tempVector.at(temp);
    }
    //null at the end to make life easier 
    seperatedParameters[tempVector.size()] = '\0';
    
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

void Command::setLeftChild(Argument* input){
    return;
}
void Command::setRightChild(Argument* input){
    return;
}
char Command::getConnector(){
    return '0';
}
