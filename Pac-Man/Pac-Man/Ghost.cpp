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
			case 0:
			{
				this->imageObject.move(this->speed, 0.00f);
				this->currentDirection = 0;
				break;
			}
			case 1:
			{
				this->imageObject.move(-(this->speed), 0.00f);
				this->currentDirection = 1;
				break;
			}
			case 2:
			{
				this->imageObject.move(0.00f, (this->speed));
				this->currentDirection = 2;
				break;
			}
			case 3:
			{
				this->imageObject.move(0.00f, -(this->speed));
				this->currentDirection = 3;
				break;
			}
		}
	}
	if (collision)
	{
		int changeDirection = this->currentDirection;
				
		switch (changeDirection)
		{
			case 0:
			{
				this->imageObject.move(-(this->speed), 0.00f);
				this->collision = false;
				this->currentDirection = 1;
				break;
			}
			case 1:
			{
				this->imageObject.move((this->speed), 0.00f);
				this->collision = false;
				this->currentDirection = 0;
				break;
			}
			case 2:
			{
				this->imageObject.move(0.00f, -(this->speed));
				this->collision = false;
				this->currentDirection = 3;
				break;
			}
			case 3:
			{
				this->imageObject.move(0.00f, this->speed);
				this->collision = false;
				this->currentDirection = 2;
				break;
			}
		}
	}

}