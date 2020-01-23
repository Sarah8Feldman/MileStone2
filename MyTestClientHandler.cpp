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
    string buffToString = buffer;
    string problem = "";
    string solution = "";

    //reading from client - getting the problem
    while (true) {
        ssize_t readVal = read(sockfd, buffer, sizeof(buffer));
//        int index = 0;
        if(!isEndOfLine(buffer)){
            problem +=buffToString;
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

bool MyTestClientHandler::isEndOfLine(char *buffer) {
    string buffToString = buffer;
    int end = buffToString.find('\r\n', 0);
    if(end != -1){
        return true;
    } else{
        return false;
    }
}