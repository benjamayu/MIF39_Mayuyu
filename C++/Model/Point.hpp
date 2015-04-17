#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point();
    Point(long _x, long _y);
    Point operator= (Point p);
    long getX();
    void setX(long _x);
    long getY();
    void setY(long _y);
    double distance(Point p);
protected:
    long x, y;
};

#endif
