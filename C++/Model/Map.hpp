#ifndef MAP_H
#define MAP_H

class Map {
public:
    Map();
    Map(unsigned long _width,unsigned long _height);
    unsigned long getWidth();
    void setWidth(unsigned long _width);
    unsigned long getHeight();
    void setHeight(unsigned long _height);
protected:
    unsigned long width,height;
};

#endif
