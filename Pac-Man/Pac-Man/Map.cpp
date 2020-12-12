#include "Map.h";

Map::Map()
{
	this->nameOfImage = "../../Graphics/brick2.jpg";
	this->wall.loadFromFile(this->nameOfImage);
}
