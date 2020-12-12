#include "PacMan.h"


PacMan::PacMan(float posX,float posY,float speed,String nameOfFile) : 
	           Ghost(posX,posY,speed,nameOfFile)
{
	this->pacMan = true;
	this->speed = 0.12f;
}

void PacMan::killPacMan()
{
	this->numberOfLifes--;
}
PacMan::~PacMan(){}