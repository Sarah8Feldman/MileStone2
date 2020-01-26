//
// Created by sarah on 24/01/2020.
//

#ifndef MILESTONE2_23_1_SEARCHER_H
#define MILESTONE2_23_1_SEARCHER_H

#include "Isearcher.h"
#include "State.h"
template<class T>
class Searcher: public Isearcher<T>{
protected:
    int numOfNodesEvaluated;

    virtual vector<State<T>*> backTraceNodes(State<T> *s){
        vector<State<T> *> stateVec;
        State<T>* tmp = s;
        while (tmp->getCameFrom() != nullptr) {
            stateVec.insert(stateVec.begin(), tmp);
            tmp = tmp->getCameFrom();
        }
        //no nodes were inserted to the vector
        if (stateVec.empty()) {
            return stateVec;
        }
        stateVec.insert(stateVec.begin(), tmp);
        return stateVec;
    };

public:
    Searcher() : numOfNodesEvaluated(0) {}

    virtual int getNumberOfNodesEvaluated() {
        return numOfNodesEvaluated;
    }

    virtual vector<State<T>*> search(Searchable<T> *searchable) = 0;

    virtual ~Searcher() {}
};

#endif //MILESTONE2_23_1_SEARCHER_H
