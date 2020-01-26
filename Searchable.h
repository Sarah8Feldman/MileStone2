//
// Created by sarah on 24/01/2020.
//

#ifndef MILESTONE2_23_1_SEARCHABLE_H
#define MILESTONE2_23_1_SEARCHABLE_H

#include "State.h"
#include <vector>
//Interface Searchable
template <class T>
class Searchable{
public:
    virtual State<T> * getInitialState() = 0;
    virtual State<T> * getGoalState() = 0;
    virtual vector< State<T>* > getAllPossibleStates(State<T> *s) = 0;
    virtual string toString() = 0;
};
#endif //MILESTONE2_23_1_SEARCHABLE_H
