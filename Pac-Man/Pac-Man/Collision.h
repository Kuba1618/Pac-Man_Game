#ifndef COLLISION_H
#define COLLISION_H
#include <SFML\Graphics.hpp>
#include <stdlib.h>

using namespace std;
using namespace sf;

class Collision
{
public:
	Collision();
	~Collision();

	void move(float x,float y);
	bool checkCollision(Collision& other,float push);
	Vector2f getPosition() { return body.getPosition();}
	Vector2f getHalfSize() { return body.getSize() / 2.0f; }
private:
	Sprite spriteOfObject;

}


#endif
