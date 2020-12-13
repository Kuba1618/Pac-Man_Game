#include "Map.h";

Map::Map()
{
	this->nameOfImage = "../../Graphics/brick2.jpg";
	this->wall.loadFromFile(this->nameOfImage);
}

void Map::drawBrick(int x,int y)
{
	this->tiles[x][y].setPosition((float)(x * (this->tile_width)), (float)(y * (this->tile_height)));
	this->tiles[x][y].setTexture(this->wall);
	this->isWall[x][y] = true;
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