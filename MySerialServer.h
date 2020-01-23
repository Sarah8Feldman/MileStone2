//
// Created by sarah on 19/01/2020.
//

#ifndef MIKESTONE2_MYSERIALSERVER_H
#define MIKESTONE2_MYSERIALSERVER_H
#include "Server.h"
#include "ClientHandler.h"

class MySerialServer : public server_side:: Server{
public:
     void open(int port, ClientHandler* myHandler);
     void stop(int socketfd);
    virtual ~MySerialServer(){} ;
};


#endif //MIKESTONE2_MYSERIALSERVER_H
