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
	bool isRunning = true;

	void startGame();
	void display(RenderWindow *window);
	void loadTextureToObject(Object *object,String nameOfImage);
	void movePacMan(Sprite *object);
	void endGame();
};
#endif