//
// Created by sarah on 19/01/2020.
//

#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include "MySerialServer.h"
using namespace std;
/**
 * open socket and wait for client to connect
 * @param port
 * @param myHandler
 */
void MySerialServer::open(int port, ClientHandler *myHandler) {

    //create a socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    cout << "Open the server socket on " << "0.0.0.0:" << (port) << endl;
    address.sin_port = htons(port);

    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }


    struct timeval tv;
    tv.tv_sec = 120;
    tv.tv_usec = 0;
    //before accepting a client - the thread goes to a timeout
    if(setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv) == -1){
        stop(socketfd);
    }
    else {
        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                   (socklen_t *) &address);
        if (client_socket == -1) {
            std::cerr << "Error accepting client" << std::endl;
        }

        myHandler->handleClient(client_socket);
//        this_thread::sleep_for(chrono::seconds(20));
    }
}
/**
 * close socket
 * @param socketfd
 */
void MySerialServer::stop(int socketfd){
    close(socketfd);
}