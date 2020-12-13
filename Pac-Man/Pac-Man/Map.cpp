#include "Map.h";

Map::Map()
{
	this->nameOfImage = "../../Graphics/brick2.jpg";
	this->wall.loadFromFile(this->nameOfImage);
}

void Map::drawBrick(int x,int y)
{
	this->kafelek[x][y].setPosition((float)(x * (this->tile_width)), (float)(y * (this->tile_height)));
	this->kafelek[x][y].setTexture(this->wall);
	this->isWall[x][y] = true;
}

void Map::loadMap()
{
	for (int y = 0; y < (this->y_titles) ; y++)
	{
		for (int x = 0; x < (this->x_titles) ; x++)
		{
			if (x == 0 || y == 0 || x == ((this->x_titles) - 1) || y == ((this->y_titles) - 1))
			{
				drawBrick(x,y);
			}
		}
	}
}

void Map::displayMap(RenderWindow *window)
{
	for (int y = 0; y < (this->y_titles); y++)
	{
		for (int x = 0; x < (this->x_titles); x++)
		{
			window->draw(this->kafelek[x][y]);
		}
	}
}