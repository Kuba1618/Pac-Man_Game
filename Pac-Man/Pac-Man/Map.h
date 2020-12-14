#ifndef MAP_H
#define MAP_H
#include <SFML\Graphics.hpp>
using namespace sf;

class Map
{
public:
	const int x_tiles = 22;
	const int y_tiles = 16;
	int mapNonMovingObjects[22][16];    // 0 - nothing; 1 - wall 2 - food 
	float tile_width = 40.0f;
	float tile_height = 40.0f; 

	Sprite tiles[22][16];
	Map();
	void fillMapNonMovingObjects();
	void showMapNonMovingObjects();
	void drawFood(int x, int y);
	void drawBrick(int x, int y);
	void loadMap();
	void displayMap(RenderWindow *window);
};
#endif