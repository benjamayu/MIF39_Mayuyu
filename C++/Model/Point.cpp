#include "Point.hpp"
#include <math.h>

Point::Point() {}

Point::Point(long _x, long _y) : x(_x), y(_y) {}

Point Point::operator=(Point p) {
    x=p.getX();
    y=p.getY();
}

long Point::getX(){
    return x;
}

void Point::setX(long _x){
    x=_x;
}

long Point::getY(){
    return y;
}

void Point::setY(long _y){
    y=_y;
}

double Point::distance(Point p) {
    return sqrt(
        (p.getX() - x)*(p.getX() - x)   //(x2-x1)^2
                +
        (p.getY() - y)*(p.getY() - y)   //(y2-y1)^2
                );
}
