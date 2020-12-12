#ifndef OBJECT_H
#define OBJECT_H
#include <SFML\Graphics.hpp>
#include "Map.h";

using namespace sf;

class Object
{
	 
public:
	int width;
	int height;
	float posX;
	float posY;
	bool startOfGame = true;
	Texture texture;
	Sprite imageObject;
	bool collision;

	
	Object(int width = 30 , int height = 30, float posX = (50.0F), float posY = (50.0F),String nameOfImage = "pacManIcon.png");
	~Object();
	int getPosX();
	int getPosY();
	Texture getTexture();
	void setTexture(String nameOfImage);
};
#endif