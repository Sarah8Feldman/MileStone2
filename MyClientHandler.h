//
// Created by sarah on 25/01/2020.
//

#ifndef MILESTONE2_23_1_MYCLIENTHANDLER_H
#define MILESTONE2_23_1_MYCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"
#include <string>
#include <unistd.h>
#include <sstream>
#include "Searcher.h"
#include "CacheManager.h"
#include "MatrixSearchable.h"

using namespace std;
template <class T>
class MyClientHandler: public ClientHandler{
private:
    Searcher<T> *searcher;
    CacheManager<string, string> *cacheManager;
    bool isEndOfLine(char* buffer);
    Solver<string, string > *solver;
public:
    MyClientHandler(Solver<string, string>* solve,  CacheManager<string, string> *manager) {
        this->solver = solve;
        this->cacheManager = manager;
    };

    void handleClient(int sockfd){
        vector<string> vec;
        string lineData;
        stringstream ss;
        char buffer[256] = {0};
        while (true) {
            int readVal = read(sockfd, buffer, 255);
            ss << buffer;
            if (isEndOfLine(ss.str())) {
                break;
            }
            if(readVal < 0){
                 perror("error reading from socket - myTestClientHendler");
             }
        }
        while (getline(ss,lineData)) {
            vec.push_back(lineData);
        }
        Searchable<Point> *matrix= new MatrixSearchable(vec);
        string problem = matrix->toString();
        string solution = this->mySolver->solve(problem);
        char* finalSolution = &solution[0];
        ssize_t writeVal = write(sockfd, finalSolution, solution.length());
        problem = "";
        if(writeVal < 0){
            perror("error writing to socket - myTestClientHendler");
        }
            }
        }
//    }

    bool isEndOfLine(const string &line) {
        if (line.substr(0).find("end") < line.size()) {
            return true;
        } else {
            return false;
        }
    }
};
#endif //MILESTONE2_23_1_MYCLIENTHANDLER_H
