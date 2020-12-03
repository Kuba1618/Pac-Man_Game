#ifndef FOOD_H
#define FOOD_H
#include <SFML\Graphics.hpp>
#include "Object.h";

using namespace sf;

class Food : public Object
{
    int howManyFood;
public:
	Food::Food(int howManyFood,String nameOfImage);
	Food::~Food();
	void eat();
};
#endif