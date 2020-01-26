//
// Created by sarah on 19/01/2020.
//

#ifndef SERVER_SOLVER_H
#define SERVER_SOLVER_H
using namespace std;

template <typename problem,typename solution>
class Solver {
public:
    virtual solution solve(problem) = 0;
};


#endif //SERVER_SOLVER_H
