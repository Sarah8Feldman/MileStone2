//
// Created by sarah on 24/01/2020.
//

#ifndef MILESTONE2_23_1_MAPSINGLETON_H
#define MILESTONE2_23_1_MAPSINGLETON_H
#include <mutex>
#include <unordered_map>
using namespace std;

class MapSingleton{
private:
    static MapSingleton* instance;
    MapSingleton();
    unordered_map<string, string> cacheMap;

public:
    static MapSingleton* getInstance();
    mutex gMutex;
    void insertToCacheMap(string problem, string solution);
    bool isInCacheMap(string problem);
};



#endif //MILESTONE2_23_1_MAPSINGLETON_H
