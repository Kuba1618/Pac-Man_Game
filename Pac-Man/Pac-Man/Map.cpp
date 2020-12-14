#include "Map.h";
#include "Brick.h";
#include "Food.h";
#include <iostream>;

using namespace std;
Map::Map(){}

void Map::fillKindOfTilesArray()
{
	for (int y = 0; y < y_tiles; y++)
	{
		for (int x = 0; x < x_tiles; x++)
		{
			kindOfTiles[x][y] = 0;
		}	
	}
}

void Map::showkindOfTiles()
{
	for (int y = 0; y < y_tiles; y++)
	{
		for (int x = 0; x < x_tiles; x++)
		{
			cout << kindOfTiles[x][y] << "   ";
		}
		cout << endl;
	}
}

void Map::loadOneFood(int x, int y)
{
	Food *food = new Food(((float)x) * (this->tile_width), ((float)y) * (this->tile_height), "food.png");
	tiles[x][y] = food->imageObject;
	kindOfTiles[x][y] = 2;
}

void Map::loadAllFood()
{
	for (int y = 0; y < (this->y_tiles); y++)
	{
		for (int x = 0; x < (this->x_tiles); x++)
		{
			if (x == 10 && y > 1 && y < 8)
			{
				loadOneFood(x, y);
			}
		}
	}
}

void Map::loadOneBrick(int x,int y)
{
	Brick *brick = new Brick(((float)x) * (this->tile_width), ((float)y) * (this->tile_height),"brick2.jpg");
	tiles[x][y] = brick->imageObject;
	kindOfTiles[x][y] = 1;
}

void Map::loadAllBricks()
{
	for (int y = 0; y < (this->y_tiles); y++)
	{
		for (int x = 0; x < (this->x_tiles); x++)
		{
			if (x == 0 || y == 0 || x == ((this->x_tiles) - 1) || y == ((this->y_tiles) - 1))
			{
				loadOneBrick(x, y);
			}
		}
	}
}

void Map::loadMap()
{
	loadAllFood();
	loadAllBricks();
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