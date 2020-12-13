#ifndef MAP_H
#define MAP_H
#include <SFML\Graphics.hpp>
using namespace sf;

class Map
{
public:
	const int x_tiles = 22;
	const int y_tiles = 16;
	bool isWall[22][16];
	const int tile_width = 30;
	const int tile_height = 30; 

	String nameOfImage;
	Texture wall;
	Sprite tiles[22][16];
	Map();
	void drawBrick(int x, int y);
	void loadMap();
	void displayMap(RenderWindow *window);
};
#endif