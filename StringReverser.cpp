//
// Created by sarah on 20/01/2020.
//

#include "StringReverser.h"
/**
 * create a new cache in constructor
 */
StringReverser::StringReverser()
{
    this->myFileManager = new FileCacheManager();
}

/**
 * if solution exist -> get it from the cache
 * if not - > solve the problem and insert to cache
 * @param problem
 * @return solution
 */
string StringReverser::solve(string problem)
{
    string solution = problem.substr(0,problem.length()-2);
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
}
/**
 * destructor
 */
StringReverser::~StringReverser()
{
    delete(this->myFileManager);
}
