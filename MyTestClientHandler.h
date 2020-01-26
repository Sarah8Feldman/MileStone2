//
// Created by sarah on 19/01/2020.
//

#ifndef SERVER_MYTESTCLIENTHANDLER_H
#define SERVER_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"

class MyTestClientHandler : public ClientHandler {
private:
    bool isEndOfLine(char* buffer);
    Solver<string, string > *mySolver;
public:
    MyTestClientHandler(Solver<string, string>* StringReverse);
    void handleClient(int sockfd);

    bool isEndOfLine(char buffer);
};


#endif //SERVER_MYTESTCLIENTHANDLER_H
