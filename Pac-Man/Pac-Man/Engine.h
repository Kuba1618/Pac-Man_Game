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
	void moveGhost(Sprite *object);
	void movePacMan(Ghost *pacMan,Sprite *object);
	void endGame();
};
#endif