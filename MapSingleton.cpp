//
// Created by sarah on 24/01/2020.
//
#include "MapSingleton.h"
MapSingleton* MapSingleton::instance = 0;
MapSingleton::MapSingleton() {}
MapSingleton *MapSingleton::getInstance() {
    if (!instance)
        instance = new MapSingleton;
    return instance;
}
void MapSingleton::insertToCacheMap(string problem, string solution){
    gMutex.lock();
    cacheMap.insert(std::make_pair(problem,solution));
    gMutex.unlock();
}

bool MapSingleton::isInCacheMap(string problem) {
    auto it = cacheMap.find(problem);
    //if key(problem) is found in the map
    if (it != this->cacheMap.end()) {
        return true;
    } else {
        return false;
    }
}