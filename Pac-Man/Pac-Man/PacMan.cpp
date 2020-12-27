#include "PacMan.h"


PacMan::PacMan(float posX,float posY,float speed,String nameOfFile) : 
	           Ghost(posX,posY,speed,nameOfFile)
{
	this->pacMan = true;
	this->speed = 0.12f;
}

void PacMan::movePacMan()
{
	if (!collision)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			this->setTexture("pacManIconLeft.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move(-(this->speed), 0.00f);
			this->currentDirection = Keyboard::Key::Left;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			this->setTexture("pacManIcon.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move((this->speed), 0.00f);
			this->currentDirection = Keyboard::Key::Right;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up))
		{

			this->setTexture("pacManIconUp.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move(0.00f, -(this->speed));
			this->currentDirection = Keyboard::Key::Up;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down))
		{
			this->setTexture("pacManIconDown.png");
			this->imageObject.setTexture(this->texture);
			this->imageObject.move(0.00f, (this->speed));
			this->currentDirection = Keyboard::Key::Down;
		}
	}
	if (collision)
	{
		if (Keyboard::isKeyPressed(this->currentDirection))
		{
			//Do nothing
		}
		else if (!Keyboard::isKeyPressed(this->currentDirection))
		{
			collision = false;
			if (Keyboard::isKeyPressed(Keyboard::Key::Left))
			{
				this->setTexture("pacManIconLeft.png");
				this->imageObject.setTexture(this->texture);
				this->imageObject.move(-(this->speed), 0.00f);
				this->currentDirection = Keyboard::Key::Left;
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Right))
			{
				this->setTexture("pacManIcon.png");
				this->imageObject.setTexture(this->texture);
				this->imageObject.move((this->speed), 0.00f);
				this->currentDirection = Keyboard::Key::Right;
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Up))
			{

				this->setTexture("pacManIconUp.png");
				this->imageObject.setTexture(this->texture);
				this->imageObject.move(0.00f, -(this->speed));
				this->currentDirection = Keyboard::Key::Up;
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Down))
			{
				this->setTexture("pacManIconDown.png");
				this->imageObject.setTexture(this->texture);
				this->imageObject.move(0.00f, (this->speed));
				this->currentDirection = Keyboard::Key::Down;
			}
		}

	}
}

void PacMan::killPacMan()
{
	numberOfLifes--;
}

PacMan::~PacMan(){}