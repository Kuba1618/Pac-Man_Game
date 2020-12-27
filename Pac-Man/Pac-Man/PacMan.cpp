#include "PacMan.h"


PacMan::PacMan(float posX,float posY,float speed,String nameOfFile) : 
	           Ghost(posX,posY,speed,nameOfFile)
{
	this->pacMan = true;
	this->speed = 0.12f;
}

void PacMan::movePacMan()
{
	/*for (int y = 0; y <= (map->y_kafli) - 2; y++)
	{
	for (int x = 0; x <= (map->x_kafli) - 2; x++)
	{
	if (pacMan->imageObject.getPosition().x + (map->tile_width) == map->kafelek[x][y].getPosition().x
	&& pacMan->imageObject.getPosition().y + (map->tile_height) == (map->kafelek[x][y]).getPosition().y)
	//&& map->isWall[x][y] == 1)
	{
	pacMan->collision = true;
	}
	}
	}*/

	if ((this->collision) == false)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			this->setTexture("pacManIconLeft.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move(-(this->speed), 0.00f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			this->setTexture("pacManIcon.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move((this->speed), 0.00f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up))
		{
			this->setTexture("pacManIconUp.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move(0.00f, -(this->speed));
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down))
		{
			this->setTexture("pacManIconDown.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move(0.00f, (this->speed));
		}
	}
}

void PacMan::killPacMan()
{
	numberOfLifes--;
}

PacMan::~PacMan(){}