//
// Created by sarah on 19/01/2020.
//

#ifndef SERVER_CACHEMANAGER_H
#define SERVER_CACHEMANAGER_H

#include <vector>
#include <string>
using namespace std;


//is there a solution to problem p?
//find the solution to P
//if not find - save the solution S for P

template <class problem,class solution>
class CacheManager {
public:
    virtual  bool isThereSolutionInMap(problem) = 0;
    virtual solution getSolution(problem) = 0;
    virtual ~CacheManager(){};
};



#endif //SERVER_CACHEMANAGER_H
