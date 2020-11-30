#ifndef GHOST_H
#define GHOST_H
#include <SFML\Graphics.hpp>
#include "Object.h";

using namespace sf;

class Ghost : public Object 
{
public:
	Ghost(int posX = 0, int posY = 0);
	~Ghost();
};
#endif // !GHOST_H
