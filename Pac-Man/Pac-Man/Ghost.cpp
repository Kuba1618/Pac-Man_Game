#include "Ghost.h"

Ghost::Ghost(float posX, float posY,float speed,String nameOfFile,int direction) : Object(posX,posY,nameOfFile)
{
	this->posX = posX;
	this->posY = posY;
	this->pacMan = false;
	this->collision = false;
	this->speed = speed;
	this->currentDirection = direction;
}
Ghost::~Ghost()
{
	cout << "Niszczenie obiektu ducha";
}

void Ghost::moveGhost(int direction)
{
	if (!collision)
	{
		switch (direction)
		{
		case 1:
		{
			this->imageObject.move(this->speed, 0.00f);
			this->currentDirection = 1;
			break;
		}
		case 2:
		{
			this->imageObject.move(-(this->speed), 0.00f);
			this->currentDirection = 2;
			break;
		}
		default:
		{
			this->imageObject.move(this->speed, this->speed);
		}
		}
	}
	if (collision)
	{
		int changeDirection = (this->currentDirection + 2) % 2 + 1;
		switch (changeDirection)
		{
		case 1:
		{
			this->imageObject.move(this->speed, 0.00f);
			this->collision = false;
			this->currentDirection = 1;
			break;
		}
		case 2:
		{
			this->imageObject.move(-(this->speed), 0.00f);
			this->collision = false;
			this->currentDirection = 2;
			break;
		}
		default:
		{
			this->imageObject.move(this->speed, this->speed);
		}
		}
	}

}