//
// Created by sarah on 26/01/2020.
//

#ifndef MILESTONE2_23_1_HEURISTIC_H
#define MILESTONE2_23_1_HEURISTIC_H
template<class T>
class Heuristic {

public:
    virtual ~Heuristic() {}
    virtual void setGoal(State<T> *goal) = 0;
    virtual double evaluateFromNode(State<T> *current) = 0;
};
#endif //MILESTONE2_23_1_HEURISTIC_H
