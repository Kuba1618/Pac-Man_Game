#include <SFML\Graphics.hpp>
#include "Object.h";
#include <iostream>

using namespace std;
using namespace sf;

void Object::setTexture(String nameOfImage)
{
	Texture texture1;

	if (!texture1.loadFromFile(nameOfImage))
	{
		cout << "Cos poszlo nie tak - plik nie zosta³ otwarty\n";
		system("exit");
	}
	this->texture = texture1;
}

Object::Object(int width, int height, float posX, float posY, String nameOfImage)
{
	this->width = width;
	this->height = height;
	this->posX = posX;
	this->posY = posY;
	setTexture(nameOfImage);
}

Object::~Object() {}
int Object::getPosX()
{
	return posX;
}
int Object::getPosY()
{
	return posY;
}
Texture Object::getTexture()
{
	return this->texture;
}