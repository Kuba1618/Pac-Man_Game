#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Object.h";
#include <iostream>

using namespace std;
using namespace sf;

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
	return this->posX;
}

int Object::getPosY()
{
	return this->posY;
}

void Object::setTexture(String nameOfImage)
{
	if (!this->texture.loadFromFile("../../Graphics/" + nameOfImage))
	{
		cout << "Cos poszlo nie tak - plik nie zostal otwarty\n";
		system("exit");
	}
	imageObject.setTexture(this->texture);
	if (Object::startOfGame)
	{
		imageObject.setPosition(posX, posY);
		startOfGame = false;
	}

}

Texture Object::getTexture()
{
	return this->texture;
}
