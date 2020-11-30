#include "Ghost.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

Ghost::Ghost(int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
}
Ghost::~Ghost()
{
	cout << "Niszczenie obiektu";
}
