//
// Created by sarah on 19/01/2020.
//

#ifndef SERVER_FILECACHEMANAGER_H
#define SERVER_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <unordered_map>

class FileCacheManager:public CacheManager<string ,string>{
private:
    //map of <problem, solution>
    unordered_map<string, string> cashMap;
public:
    FileCacheManager();
    bool isThereSolutionInMap(string problem);
    string getSolution(string problem);
    void insert(string problem, string solution);
    void insertAllFilesToMap();
};


#endif //SERVER_FILECACHEMANAGER_H
