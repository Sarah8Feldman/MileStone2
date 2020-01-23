//
// Created by sarah on 19/01/2020.
//

#ifndef MIKESTONE2_CLIENTHANDLER_H
#define MIKESTONE2_CLIENTHANDLER_H
class ClientHandler {

public:
    virtual void handleClient(int sock_fd) = 0 ;
    virtual ~ClientHandler(){} ;

};
#endif //MIKESTONE2_CLIENTHANDLER_H
