//
// Created by sarah on 25/01/2020.
//

#include "SolutionAnalyst.h"
SolutionAnalyst::SolutionAnalyst(){};
SolutionAnalyst::~SolutionAnalyst(){};
string SolutionAnalyst::getPathToGoal(vector<State<Point>*> vec) {
    string path;
    if (vec.empty()) {
        path = "";
    }
    for (int i = 1; i < vec.size(); i++) {
//        State<Point> *s = vec[i - 1];
        Point *prevPos = vec[i - 1]->getState();
        Point *postPos = vec[i]->getState();
        path += this->getDir(prevPos, postPos) + ", ";
    }
    path.erase(path.size() - 2, path.size());
}

string SolutionAnalyst::getDir( Point *befor, Point *after) {
    string retVal = "";
    if (after->getX() > befor->getX()) {
        retVal = "Down";
    }
    else if (after->getX() < befor->getX()) {
        retVal = "Up";
    }
    else if (after->getY() > befor->getY()) {
        retVal = "Right";
    }
    else{
        retVal = "Left";
    }
    return retVal;
}



