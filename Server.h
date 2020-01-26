//
// Created by sarah on 19/01/2020.
//

#ifndef MIKESTONE2_SERVER_H
#define MIKESTONE2_SERVER_H

#include "ClientHandler.h"

namespace server_side {

    class Server {
    public:
        virtual void open(int port, ClientHandler* myHandler) = 0;
        virtual void stop(int socketfd) = 0;
        virtual ~Server(){} ;
    };
}





#endif //MIKESTONE2_SERVER_H
