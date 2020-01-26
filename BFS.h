//
// Created by sarah on 24/01/2020.
//

#ifndef MILESTONE2_23_1_BFS_H
#define MILESTONE2_23_1_BFS_H

#include "Searcher.h"
#include "State.h"
#include "Searchable.h"
#include <queue>

using namespace std;

template<class T>
class BFS : public Searcher<T> {

public:
    BFS() {}

    vector<State<T> *> search(Searchable<T> *searchable) override;

    virtual ~BFS() {}
};

template<class T>
vector<State<T> *> BFS<T>::search(Searchable<T> *searchable) {
    vector<State<T> *> adjacentNodes;
    State<T> *stateNode;
    stateNode = searchable->getInitialState();
    //create a queue
    queue<State<T> *> queue;
    //get the initial state
    queue.push(stateNode);
    stateNode->setCameFrom(nullptr);
    this->numOfNodesEvaluated++;

    while (!queue.empty()) {
        stateNode = queue.front();
        queue.pop();

        if (searchable->getGoalState() == stateNode) {
            break;
        }
        adjacentNodes = searchable->getAllPossibleStates(stateNode);
        //check if we visited adjacent nodes
        for (auto iter: adjacentNodes) {
            State<T> *n = iter;
            if (stateNode->getCost() == -1) {
                continue;
            }
            if (!n->isVisited()) {
                n->setCameFrom(stateNode);
                this->numOfNodesEvaluated++;
                //add to the queue
                queue.push(n);
            }
        }
    }
    return this->backTraceNodes(searchable->getGoalState());
}


#endif //MILESTONE2_23_1_BFS_H
