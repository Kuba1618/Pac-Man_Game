#ifndef MAP_H
#define MAP_H
#include <SFML\Graphics.hpp>
#include "Ghost.h";

using namespace sf;

class Map
{
public:
	const int x_tiles = 22;
	const int y_tiles = 16;
	int kindOfTiles[22][16];    // 0 - nothing; 1 - wall; 2 - food; 3 - ghost; 4 - pacMan 
	float tile_width = 40.0f;
	float tile_height = 40.0f; \
	int counter = 0;
	
	Ghost *ghosts[2];
	Sprite tiles[22][16];
	Map();
	void fillKindOfTilesArray();
	void showkindOfTiles();
	void loadOneBrick(int x, int y);
	void loadAllBricks();
	void loadOneFood(int x, int y);
	void loadAllFood();
	void loadGhost(int x, int y);
	void loadAllGhosts();
	void loadMap();
	void displayMap(RenderWindow *window);
};
#endif