#ifndef ENGINE_H
#define ENGINE_H

#include <SFML\Graphics.hpp>
#include "Map.h";
#include "Object.h";
#include "Ghost.h";
#include "Brick.h";
#include "PacMan.h";
#include "Food.h";
#include "Results.h";
#include <windows.h>
#include <iostream>

using namespace std;
using namespace sf;

class Engine
{

public:
	bool isRunning = true;
	
	void startGame();
	void display(RenderWindow *window);
	void collisionPacManGhost(PacMan *object1, Ghost *object2, Results *results);
	void collisionPacManFood(PacMan *object1, Food *object2, Map *map, Results *results);
	void collisionPacManBricks(Ghost *object1, Brick *object2);
	void collisionGhostBricks(Ghost *object1, Brick *object2);
	void endGame();
};
#endif