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
	for (int y = 0; y < (this->y_kafli) ; y++)
	{
		for (int x = 0; x < (this->x_kafli) ; x++)
		{
			if (x == 0 || y == 0 || x == ((this->x_kafli) - 1) || y == ((this->y_kafli) - 1))
			{
				drawBrick(x,y);
			}
		}
	}

}