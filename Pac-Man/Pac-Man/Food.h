#ifndef FOOD_H
#define FOOD_H
#include <SFML\Graphics.hpp>
#include "Object.h";

using namespace sf;

class Food : public Object
{
public:
	Food::Food(float posX = 55.0f ,float posY = 50.0f ,String nameOfImage = "food.png");
	Food::~Food();
	void eat();
};
#endif