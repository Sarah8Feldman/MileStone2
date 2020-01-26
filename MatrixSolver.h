//
// Created by sarah on 26/01/2020.
//

#ifndef MILESTONE2_23_1_MATRIXSOLVER_H
#define MILESTONE2_23_1_MATRIXSOLVER_H

#include "Solver.h"
#include <string>
#include "Astar.h"
#include "ManhattanDistance.h"
#include "FileCacheManager.h"

using namespace std;
class MatrixSolver : public Solver <string,string>{
private:
    FileCacheManager *myFileManager;
public:
    MatrixSolver(FileCacheManager *cache, Searchable<Point> *matrix){
        this->myFileManager = cache;
    };

    vector<State<Point> *> solve(Searchable<Point> *searchable){
        if(this->myFileManager->isThereSolutionInMap(problem))
        {
            return this->myFileManager->getSolution(problem);
        }
        else {
        Heuristic<Point>* h = new ManhattanDistance();
        Searcher<Point> *searcher = new AStar<Point>(h);
        return searcher->search(searchable);
    }
};
#endif //MILESTONE2_23_1_MATRIXSOLVER_H
