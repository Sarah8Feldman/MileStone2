//
// Created by sarah on 24/01/2020.
//

#ifndef MILESTONE2_23_1_ASTAR_H
#define MILESTONE2_23_1_ASTAR_H
#include "BeastFirstSearch.h"
#include "State.h"
#include "Heuristic.h"

template<class T>
class AStar : public BestFirstSearch<T> {
private:
    Heuristic<T> *myHeuristic;
    double x1, y1, x2, y2;

protected:
     double costBetweenNodes(State<T> *start, State<T> *end) const {
         if (start == end) {
             Point *point = end->getState();
             x2 = point->getX();
             y2 = point->getY();
             return manhatanDistance();
         }
         return start->getCost() + end->getOriginalCost();
     }

public:
    explicit AStar(Heuristic<T> *h) {
        myHeuristic = h;
    }

    vector<State<T> *> search(Searchable<T> *searchable) {
//         State<Point> *goal = getGoalFromSearchable(searchable);
          x1 = getGoalFromSearchable(searchable)->getState()->getX();
          y1 = getGoalFromSearchable(searchable)->getState()->getY();
         myHeuristic->setGoal(searchable->getGoalState());
        return BestFirstSearch<T>::search(searchable);
    }

    double manhatanDistance() {
        double val = abs(x1 - x2);
        val += abs(y1 - y2);
        return val;
    }

    State<Point>* getGoalStateFromSearchable(Searchable<T> *searchable) {
        return searchable->getGoalState();
    }

    int getNumOfNodesEvaluated() {
        return BestFirstSearch<T>::getNumberOfNodesEvaluated();
    }

    virtual ~AStar() {}

};


#endif //MILESTONE2_23_1_ASTAR_H
