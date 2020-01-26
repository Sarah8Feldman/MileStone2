//
// Created by sarah on 24/01/2020.
//

#ifndef MILESTONE2_23_1_MATRIXSEARCHABLE_H
#define MILESTONE2_23_1_MATRIXSEARCHABLE_H

#include "Searchable.h"
#include "Point.h"
#include "Matrix.h"

using namespace std;
//template <class T>
class MatrixSearchable : public Searchable<Point> {
private:
    Matrix<Point> *myMatrix;
    State<Point> **stateMatrix;

public:
    MatrixSearchable(vector<string> vec){
//        vector<string> vec = myMatrix->lineParser(s);
        myMatrix->createStateMatrix(vec);
    }

    State<Point> *getInitialState() {
        return stateMatrix[myMatrix->getStartRow()* myMatrix->getNumOfColums() + myMatrix->getStartColum()];
    }

    State<Point> *getGoalState() {
        return stateMatrix[myMatrix->getGoalRow() * myMatrix->getNumOfColums() + myMatrix->getGoalColum()];
    }

    vector<State<Point> *> getAllPossibleStates(State<Point> *s) {
//        State<T> t = s;
        Point *point = s->getState();
        int currRow = point->getX();
        int currCol = point->getY();
        vector<State<Point> *> vec;

        // Up neighbor
        if (currRow > 0) {
            vec.push_back(stateMatrix[(currRow - 1) * myMatrix->getNumOfColums() + currCol]);
        }
        // Down neighbor
        if (currRow < myMatrix->getNumOfRows() - 1) {
            vec.push_back(stateMatrix[(currRow + 1) * myMatrix->getNumOfColums() + currCol]);
        }
        // Left neighbor
        if (currCol > 0) {
            vec.push_back(stateMatrix[currRow * myMatrix->getNumOfColums() + (currCol - 1)]);
        }
        // Right neighbor
        if (currCol < myMatrix->getNumOfColums() - 1) {
            vec.push_back(stateMatrix[currRow * myMatrix->getNumOfColums() + (currCol + 1)]);
        }
        return vec;
    }

    string toString(){
        string str;
        for (int i = 0; i < myMatrix->getNumOfColums() * myMatrix->getNumOfRows(); i++) {
            str += to_string((int)stateMatrix[i]->gerCost()) + ",";
        }
        str.pop_back(); // Remove the last comma and add a separator
        // Getting the start and goal points
        str += "~" + to_string(myMatrix->getStartRow()) + "," + to_string(myMatrix->getStartColum());
        str += "~" + to_string(myMatrix->getGoalRow()) + "," + to_string(myMatrix->getGoalColum());
        return str;

    }

    virtual ~MatrixSearchable();
};
#endif //MILESTONE2_23_1_MATRIXSEARCHABLE_H
