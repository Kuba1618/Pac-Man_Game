#include <SFML\Graphics.hpp>
#include "Object.h";
#include <iostream>

using namespace std;
using namespace sf;

Object::Object() {}
Object::~Object() {}
int Object::getPosX()
{
	return posX;
}
int Object::getPosY()
{
	return posY;
}
