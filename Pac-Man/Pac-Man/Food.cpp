#include <iostream>
#include <SFML\Graphics.hpp>
#include "Food.h";

using namespace std;

Food::Food(int howMany,String nameOfImage) : howManyFood(howMany)
{
	setTexture(nameOfImage);
}
Food::~Food(){}

void Food::eat()
{
	this->howManyFood--;
	cout << "Pozostalo: " << howManyFood << "sztuk jedzenia\n";
}
