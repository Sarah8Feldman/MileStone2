//
// Created by sarah on 24/01/2020.
//

#ifndef MILESTONE2_23_1_ISEARCHER_H
#define MILESTONE2_23_1_ISEARCHER_H

#include "Searchable.h"
template <class T>
class Isearcher{
public:
    virtual vector<State<T>*> search(Searchable<T>* searchable) = 0;
    virtual int getNumOfNodesEvaluated() = 0;
};

#endif //MILESTONE2_23_1_ISEARCHER_H
