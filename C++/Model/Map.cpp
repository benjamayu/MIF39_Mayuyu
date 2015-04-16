#include "Map.hpp"

Map::Map(){}
Map::Map(unsigned long _width,unsigned long _height) : width(_width),height(_height) {}

unsigned long Map::getWidth(){
	return width;
}
void Map::setWidth(unsigned long _width){
	width=_width;
}
unsigned long Map::getHeight(){
	return height;
}
void Map::setHeight(unsigned long _height){
	height=_height;
}
