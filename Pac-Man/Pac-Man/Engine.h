#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Object.h";
#include "Ghost.h";

using namespace std;
using namespace sf;

class Engine
{
public:
	bool isRunning = true;

	void startGame();
	void display(RenderWindow *window);
	//void setTexture(Object *object,String nameOfImage);
	void moveGhost(Sprite *object);
	void movePacMan(Ghost *pacMan,Sprite *object);
	void endGame();
};
#endif