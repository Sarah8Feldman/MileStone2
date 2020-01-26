//
// Created by sarah on 20/01/2020.
//

#ifndef SERVER_STRINGREVERSER_H
#define SERVER_STRINGREVERSER_H

#include <string>
#include "Solver.h"
#include "FileCacheManager.h"
using namespace std;

class StringReverser : public Solver <string,string> {
private:
    FileCacheManager *myFileManager;
public:
/**
 * create a new cache in constructor
 */
    StringReverser(FileCacheManager *cache){
            this->myFileManager = cache;
    };

    /**
 * if solution exist -> get it from the cache
 * if not - > solve the problem and insert to cache
 * @param problem
 * @return solution
 */
    string solve(string problem){
        string solution = problem;
//        string solution = problem.substr(0,problem.length()-2);
//  search in cache
        if(this->myFileManager->isThereSolutionInMap(problem))
        {
            return this->myFileManager->getSolution(problem);
        }
        else {
//        solve the problem
            char tmp;
            int counter = solution.length() - 1;
            for (int i = 0; i < solution.length() / 2; i++) {
                tmp = solution[counter];
                solution[counter] = solution[i];
                solution[i] = tmp;
                counter--;
            }
//        insert to cache
            this->myFileManager->insert(problem, solution);
            solution += "\r\n";
            return solution;
        }
    };
    string toString(){};
    /**
 * destructor
 */
    ~StringReverser(){
        delete(this->myFileManager);
    };
};


#endif //SERVER_STRINGREVERSER_H
