#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Object.h";
#include "Ghost.h";
#include "Map.h";

using namespace std;
using namespace sf;

class Engine
{
public:
	bool isRunning = true;

	void startGame();
	void display(RenderWindow *window);
	//void moveObject(Ghost *ghost, Map *map);
	void moveGhost(Sprite *object,Ghost *ghost,int direction);
	void movePacMan(Map *map, Ghost *pacMan, Sprite *player);
	void endGame();
};
#endif