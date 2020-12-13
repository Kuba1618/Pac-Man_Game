#ifndef MAP_H
#define MAP_H
#include <SFML\Graphics.hpp>
using namespace sf;

class Map
{
public:
	const int x_kafli = 22;
	const int y_kafli = 16;
	char type[22][16];
	bool isWall[22][16];
	const int tile_width = 30;
	const int tile_height = 30; 

	String nameOfImage;
	Texture wall;
	Sprite kafelek[22][16];
	Map();
	void drawBrick(int x, int y);
	void loadMap();
};
#endif