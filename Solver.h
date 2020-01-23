//
// Created by sarah on 19/01/2020.
//

#ifndef SERVER_SOLVER_H
#define SERVER_SOLVER_H
using namespace std;

template <class problem,class solution>
class Solver {
public:
    virtual solution solve(problem) = 0;
    virtual ~Solver();
};


#endif //SERVER_SOLVER_H
