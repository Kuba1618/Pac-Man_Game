#include <iostream>
#include <SFML\Graphics.hpp>
#include "Food.h";

using namespace std;

Food::Food(float posX, float posY,String nameOfImage) : Object(posX, posY, nameOfImage)
{
	howManyFood++;
}
Food::~Food()
{
	eat();
}

void Food::eat()
{
	this->howManyFood--;
	cout << "Pozostalo: " << howManyFood << "sztuk jedzenia\n";
}
