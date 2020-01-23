//
// Created by sarah on 20/01/2020.
//

#ifndef SERVER_STRINGREVERSER_H
#define SERVER_STRINGREVERSER_H

#include <string>
#include "Solver.h"
#include "FileCacheManager.h"
using namespace std;

class StringReverser : public Solver <string,string> {
private:
    FileCacheManager *myFileManager;
public:
    StringReverser();
    string solve(string problem);
    ~StringReverser();
};


#endif //SERVER_STRINGREVERSER_H
