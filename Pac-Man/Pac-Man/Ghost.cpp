#include "Ghost.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

Ghost::Ghost(float posX, float posY,float speed,String nameOfFile) : Object(30,30,posX,posY,nameOfFile)
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
