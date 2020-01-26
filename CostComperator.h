//
// Created by sarah on 24/01/2020.
//

#ifndef MILESTONE2_23_1_COSTCOMPERATOR_H
#define MILESTONE2_23_1_COSTCOMPERATOR_H

#include "State.h"
#include "Point.h"

template<class T>
class CostComparator {
public:
    bool operator()(const State<T> *firstState, const State<T> *secState) const {
        if(firstState->getCost() == secState->getCost()){
            Point * point1 = firstState->getState();
            Point * point2 = secState->getState();
            double point1X = point1->getX();
            double point2X = point2->getX();
            if(point1X == point2X)
                return point1X < point2X;
            return point1X < point2X;
        }
        return firstState->getCost() < secState->getCost();
    }
};
#endif //MILESTONE2_23_1_COSTCOMPERATOR_H
