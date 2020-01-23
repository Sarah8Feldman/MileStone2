//
// Created by sarah on 19/01/2020.
//

#include <fstream>
#include <iostream>
#include <dirent.h>
#include "FileCacheManager.h"
/**
 * in the constructor we check for existing problems(file names in the folder) and add them to map
 */
FileCacheManager::FileCacheManager(){
    insertAllFilesToMap();
}
/**
 * checks for an existing problem and solution in ncacheMap
 * @param problem
 * @return true if problem had already been solved
 */
bool FileCacheManager::isThereSolutionInMap(string problem) {
    string solution;
    auto it = cashMap.find(problem);
    //if key(problem) is found in the map
    if (it != this->cashMap.end()) {
        return true;
    } else {
        return false;
    }
}
/**
 *
 * @param problem
 * @return  the solution for the problem
 */
string FileCacheManager:: getSolution(string problem){
        return cashMap[problem];
}
/**
 * Insert a problem and it's solution
 * @param problem
 * @param solution
 */
void FileCacheManager:: insert(string problem, string solution){
    cashMap.insert(problem,solution);
    ofstream out_file;
    string fileName = problem;
    out_file.open("../problemFiles/" + fileName + ".txt", std::ios::binary);
    out_file.write((char*)&solution, sizeof(solution));
    out_file.close();
}
/**
 * in case there are existing problems that are not in the cache, but are in the file system - add them ti cache
 */
void FileCacheManager ::insertAllFilesToMap(){
    vector<string> nameList;
    DIR *dir;
    struct dirent *ent;
    //get all file names(all problems)
    if ((dir = opendir ("../problemFiles")) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            nameList.push_back(ent->d_name);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("cant open folder and search foe files");
    }

//    get all the solutions foe the problems we found
//    update the cacheMap
    ifstream in_file;
    string solution = "";
    int i = 0;
    while (!nameList.empty()) {
        string problem = nameList[i];
        in_file.open(problem, std::ios::binary);
        if (!in_file) {
            cerr << "can't find file" << endl;
        } else {
            in_file.read((char *) &solution, sizeof(solution));
            in_file.close();
            cashMap.insert(problem, solution);
            nameList.pop_back();
            i++;
        }
    }
}
