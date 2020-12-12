#ifndef FOOD_H
#define FOOD_H
#include <SFML\Graphics.hpp>
#include "Object.h";

using namespace sf;

class Food : public Object
{
    int howManyFood;
public:
	Food::Food(int howManyFood = 5,float posX = 55.0f ,float posY = 50.0f ,String nameOfImage = "food.png");
	Food::~Food();
	void eat();
};
#endif