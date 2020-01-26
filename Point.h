//
// Created by sarah on 24/01/2020.
//

#ifndef MILESTONE2_23_1_POINT_H
#define MILESTONE2_23_1_POINT_H
class Point {
private:
    int x;
    int y;
public:
    Point(int row, int colum){
        this->x = row;
        this->y = colum;
    }

    int getX(){
        return this->x;
    };
    int getY(){
        return this->y;
    };

    bool operator==(const Point *pos) const {
        return (this->x == pos->x) && (this->y == pos->y);
    }
};
#endif //MILESTONE2_23_1_POINT_H
