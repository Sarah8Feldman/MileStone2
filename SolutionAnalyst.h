//
// Created by sarah on 25/01/2020.
//

#ifndef MILESTONE2_23_1_SOLUTIONANALYST_H
#define MILESTONE2_23_1_SOLUTIONANALYST_H

#include "string"
#include "Point.h"
#include "State.h"
#include <vector>
using namespace std;
class SolutionAnalyst{
public:
    SolutionAnalyst();
    string getPathToGoal(vector<State<Point>*> vec);
    string getDir(Point *befor, Point *after);
    virtual ~SolutionAnalyst();
};
#endif //MILESTONE2_23_1_SOLUTIONANALYST_H
