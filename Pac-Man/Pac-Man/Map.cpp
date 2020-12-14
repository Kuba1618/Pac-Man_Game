#include "Map.h";
#include "Brick.h";
#include "Food.h";
#include <iostream>;

using namespace std;
Map::Map(){}

void Map::fillIsWall()
{
	for (int i = 0; i<22; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			mapNonMovingObjects[i][j] = 0;
		}	
	}
}
void Map::showWall()
{
	for (int i = 0; i<22; i++)
	{
		for (int j = 0; j<16; j++)
			cout << mapNonMovingObjects[i][j] << "   ";

		cout << endl;
	}
}

void Map::drawFood(int x, int y)
{
	Food *food = new Food((float)x * (this->tile_width), (float)y * (this->tile_height), "food.png");
	tiles[x][y] = food->imageObject;
	mapNonMovingObjects[x][y] = 1;
}

void Map::drawBrick(int x,int y)
{
	Brick *brick = new Brick((float)x * (this->tile_width), (float)y * (this->tile_height),"brick2.jpg");
	tiles[x][y] = brick->imageObject;
	mapNonMovingObjects[x][y] = 1;
}

void Map::loadMap()
{
	for (int y = 0; y < (this->y_tiles) ; y++)
	{
		for (int x = 0; x < (this->x_tiles) ; x++)
		{
			if (x == 0 || y == 0 || x == ((this->x_tiles) - 1) || y == ((this->y_tiles) - 1))
			{
				drawBrick(x,y);
			}
			if (x ==10 && y > 1 &&y < 8)
			{
				drawFood(x, y);
			}
		}
	}
}

void Map::displayMap(RenderWindow *window)
{
	for (int y = 0; y < (this->y_tiles); y++)
	{
		for (int x = 0; x < (this->x_tiles); x++)
		{
			window->draw(this->tiles[x][y]);
		}
	}
}