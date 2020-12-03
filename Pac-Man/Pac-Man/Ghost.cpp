#include "Ghost.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

Ghost::Ghost(float posX, float posY,String nameOfFile) : Object(30,30,posX,posY,nameOfFile)
{
	this->posX = posX;
	this->posY = posY;
	this->pacMan = false;
	this->collision = false;
	this->speed = 0.008f;
}
Ghost::~Ghost()
{
	cout << "Niszczenie obiektu ducha";
}
