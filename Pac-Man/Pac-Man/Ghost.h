#ifndef GHOST_H
#define GHOST_H
#include <SFML\Graphics.hpp>
#include "Object.h";

using namespace sf;

class Ghost : public Object 
{
public:
	Ghost(float posX = (120.0F), float posY = (200.0F),String nameOfFile = "orangeGhost.jpg");
	~Ghost();
};
#endif // !GHOST_H
