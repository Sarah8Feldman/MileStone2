//
// Created by sarah on 19/01/2020.
//

#include <stdio.h>
#include <string>
#include <unistd.h>
#include "MyTestClientHandler.h"
using namespace std;
MyTestClientHandler::MyTestClientHandler(Solver<string, string>* StringReverse){
    this->mySolver = StringReverse;
}

void MyTestClientHandler::handleClient(int sockfd){
    char buffer[256] = {0};
    int i = 0;

    string problem = "";
    string solution = "";
    int readVal = read(sockfd, buffer, sizeof(buffer));
    string buffToString = buffer;
    //reading from client - getting the problem
    while (true) {
        if(!isEndOfLine(buffer[i])){
            problem +=buffer[i];
            i++;
            continue;
        }
        if(readVal < 0){
            perror("error reading from socket - myTestClientHendler");
        }
//      getting the solution and writing it back
        else{
            solution = this->mySolver->solve(problem);
            char* finalSolution = &solution[0];
            ssize_t writeVal = write(sockfd, finalSolution, solution.length());
            problem = "";
            if(writeVal < 0){
                perror("error writing to socket - myTestClientHendler");
            }
        }
        break;
    }
}

bool MyTestClientHandler::isEndOfLine(char buffer) {
    if(buffer == '\n' || buffer == '\r'){
        return true;
    } else{
        return false;
    }
}