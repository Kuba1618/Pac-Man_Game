#ifndef OBJECT_H
#define OBJECT_H
#include <SFML\Graphics.hpp>

using namespace sf;

class Object
{
public:
	int width;
	int height;
	int posX;
	int posY;
	Texture texture;
	Object();
	~Object();
	int getPosX();
	int getPosY();
};
#endif