#include "Ghost.h"

Ghost::Ghost(float posX, float posY,float speed,String nameOfFile) : Object(posX,posY,nameOfFile)
{
	this->posX = posX;
	this->posY = posY;
	this->pacMan = false;
	this->collision = false;
	this->speed = speed;
}
Ghost::~Ghost()
{
	cout << "Niszczenie obiektu ducha";
}

void Ghost::moveGhost(int direction)
{
	switch (direction)
	{
	case 1:
	{
		this->imageObject.move(this->speed, 0.00f);
		break;
	}
	case 2:
	{
		this->imageObject.move(-(this->speed), 0.00f);
		break;
	}
	default:
	{
		this->imageObject.move(this->speed, this->speed);
	}
	}
}