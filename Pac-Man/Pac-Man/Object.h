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
	bool collision;

	
	Object(float posX = (50.0F), float posY = (50.0F),String nameOfImage = "pacManIcon.png");
	~Object();
	Texture getTexture();
	void setTexture(String nameOfImage);
};
#endif