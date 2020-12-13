#include <iostream>
#include <SFML\Graphics.hpp>
#include "Food.h";

using namespace std;

Food::Food(int howMany,float posX, float posY,String nameOfImage) : Object(posX, posY, nameOfImage)
{
	this->howManyFood = howMany;
	this->setTexture(nameOfImage);
}
Food::~Food(){}

void Food::eat()
{
	this->howManyFood--;
	cout << "Pozostalo: " << howManyFood << "sztuk jedzenia\n";
}
