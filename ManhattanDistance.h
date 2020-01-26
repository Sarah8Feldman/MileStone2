//
// Created by sarah on 26/01/2020.
//

#ifndef MILESTONE2_23_1_MANHATTANDISTANCE_H
#define MILESTONE2_23_1_MANHATTANDISTANCE_H
#include "Heuristic.h"
#include "State.h"
#include "Point.h"
#include <cmath>

class ManhattanDistance : public Heuristic<Point> {
    State<Point>* m_goal;

public:
    ManhattanDistance() : m_goal(nullptr) {}
    virtual ~ManhattanDistance() {}

    virtual void setGoal(State<Point>* goal) {
        m_goal = goal;
    }

    virtual double evaluateFromNode(State<Point>* current) {
        double val;
        val = abs(m_goal->getState()->getX() - current->getState()->getX());
        val += abs(m_goal->getState()->getY() - current->getState()->getY());
        return val;
    }
};
#endif //MILESTONE2_23_1_MANHATTANDISTANCE_H
