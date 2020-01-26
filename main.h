//
// Created by sarah on 21/01/2020.
//

#ifndef SERVER_MAIN_H
#define SERVER_MAIN_H

#include <string>
#include "Solver.h"
#include "StringReverser.h"
#include "Server.h"
#include "Server.h"
#include "MySerialServer.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"

using namespace std;

namespace boot {
    class Main{
    public:
        void main(int port) {
            FileCacheManager *cache = new FileCacheManager;
            Solver<string, string> *solver = new StringReverser(cache);
            ClientHandler *myClient = new MyTestClientHandler(solver);
            server_side::Server *serialServer = new MySerialServer();
            serialServer->open(port,myClient);


        }
    };
}
#endif //SERVER_MAIN_H
