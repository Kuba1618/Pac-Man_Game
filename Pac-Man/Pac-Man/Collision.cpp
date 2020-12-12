#include "Collision.h";
#include <SFML\Graphics.hpp>;

Collision::Collision(Sprite &body) : spriteOfObject(body)
{

}

Collision::~Collision(){}

bool Collision::checkCollision(Collision& other, float push)
{
	Vector2f otherPosition = other.getPosition();
	Vector2f otherHalfSize = other.getHalfSize();
	Vector2f thisPosition = this->getPosition();
	Vector2f thisHalfSize = this->getHalfSize();
	
	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float interSectX = abs(deltaX) - (otherHalfSize.x -thisHalfSize.x);
	float interSectY = abs(deltaY) - (otherHalfSize.y - thisHalfSize.y);

	if (interSectX < 0.0f && interSectY <0.0f)
	{
		push = min(max(push, 0.0f), 1.0f);

			if (interSectX > interSectY)
			{
				if (deltaX > 0.0f)
				{
					move(interSectX * (1.0f - push), 0.0f);
					other.move(-interSectX*push, 0.0f);
				}
			}
			else
			{
				if (deltaY > 0.0f)
				{
					move(interSectY * (1.0f - push), 0.0f);
					other.move(0.0f,-interSectY * push);
				}
				else
				{
					move(0.0f, -interSectY * (1.0f - push));
					other.move(0.0f,interSectY * push); 
				}
			}
	}		

	return false;
}

Vector2f Collision::getPosition() 
{ 
	return spriteOfObject.getPosition(); 
}

void Collision::move(float x,float y)
{

}