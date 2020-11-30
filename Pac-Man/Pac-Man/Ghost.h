#ifndef GHOST_H
#define GHOST_H
#include <SFML\Graphics.hpp>
#include "Object.h";

using namespace sf;

class Ghost : public Object 
{
public:
	Ghost(float posX = (0.0F), float posY = (0.0F),String nameOfFile="");
	~Ghost();
};
#endif // !GHOST_H
