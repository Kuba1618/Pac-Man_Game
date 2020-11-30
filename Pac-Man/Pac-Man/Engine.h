#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Object.h";

using namespace std;
using namespace sf;

class Engine
{
public:

	void startGame();
	void display(RenderWindow *window);
	Sprite drawObject(Object *object,String nameOfImage);
	void endGame();
};
#endif