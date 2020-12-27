#ifndef ENGINE_H
#define ENGINE_H

#include <SFML\Graphics.hpp>
#include "Map.h";
#include "Object.h";
#include "Ghost.h";
#include "Brick.h";
#include "PacMan.h";
#include "Food.h";
#include <iostream>

using namespace std;
using namespace sf;

class Engine
{
public:
	bool isRunning = true;

	void startGame();
	void display(RenderWindow *window);
	//void moveObject(Ghost *ghost, Map *map);
	void collision(Ghost *object1, Ghost *object2);
	void collisionOfFood(Ghost *object1, Food *object2);
	void collisionOfBricks(Ghost *object1, Brick *object2);
	void endGame();
};
#endif