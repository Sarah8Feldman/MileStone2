//
// Created by sarah on 24/01/2020.
//

#ifndef MILESTONE2_23_1_STATE_H
#define MILESTONE2_23_1_STATE_H

#include <string>
using namespace std;

template <class T>
class State{
private:
    T *state;
    double cost;
    State<T> *cameFrom;
    bool isVisited;

public:
    explicit State(T *state){
        this->state = state;
        cost = 0;
        cameFrom = nullptr;
        isVisited = false;
    }
    State(T *state, double coast){
        this->state = state;
        cost = coast;
        cameFrom = nullptr;
        isVisited = false;
    }

    void setCost(double c){
        this->cost = c;
    }

    double gerCost(){
        return this->cost;
    }

    double getOriginalCost() const {
        if (cameFrom == nullptr) {
            return cost;
        }
        return cost - cameFrom->getCost();
    }
    void setCameFrom(State<T> *s){
        this->cameFrom = s;
        isVisited = true;
    }

    State<T> *getCameFrom(){
        return this->cameFrom;
    }

     T *getState(){
         return this->state;
    }

    bool isNodeVisited(){
        return this->isVisited;
    }

    bool operator==(const State<T> *s) {
        return state == s->getState();
    }

    bool operator!=(const State<T> *s) {
        return !(*this == s);
    }

    State<T> &operator=(const State<T> *s) {
        cost = s->getCost();
        state = s->getState();
        isVisited = s->isVisited();
        cameFrom = s->getCameFrom();
        return *this;
    }

};

#endif //MILESTONE2_23_1_STATE_H
