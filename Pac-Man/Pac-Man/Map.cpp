#include "Map.h";

Map::Map()
{
	this->nameOfImage = "brick2.jpg";
	this->wall.loadFromFile(this->nameOfImage);
}
