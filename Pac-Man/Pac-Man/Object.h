#ifndef OBJECT_H
#define OBJECT_H
#include <SFML\Graphics.hpp>

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

	void setTexture(String nameOfImage);
	Object(int width = 30 , int height = 30, float posX = (50.0F), float posY = (50.0F),String nameOfImage = "PacManGhostRight.jpg");
	~Object();
	int getPosX();
	int getPosY();
	Texture getTexture();
};
#endif