#ifndef GHOST_H
#define GHOST_H
#include <SFML\Graphics.hpp>
#include "Object.h";
#include <iostream>

using namespace sf;
using namespace std;

class Ghost : public Object 
{
public:
	bool pacMan;
	float speed;
	bool collision;
	int currentDirection;
	Ghost(float posX = (120.0F), float posY = (200.0F),float speed = 0.03f,String nameOfFile = "orangeGhost.png",int direction = 1);
	~Ghost();
	void moveGhost(int direction);
};
#endif // !GHOST_H
