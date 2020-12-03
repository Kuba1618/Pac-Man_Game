#include "PacMan.h"


PacMan::PacMan(float posX,float posY, String nameOfFile) : 
	           Ghost(posX,posY,nameOfFile)
{
	this->pacMan = true;
	this->speed = 0.12f;
}

void PacMan::killPacMan()
{
	this->numberOfLifes--;
}
PacMan::~PacMan(){}