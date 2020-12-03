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
	void loadMap(Map *map);
	void display(RenderWindow *window);
	//void moveObject(Ghost *ghost, Map *map);
	void moveGhost(Sprite *object,int direction);
	void movePacMan(Map *map, Ghost *pacMan, Sprite *player);
	void endGame();
};
#endif