#include "PacMan.h"


PacMan::PacMan(float posX,float posY, String nameOfFile) : 
	           Ghost(posX,posY,nameOfFile){}

void PacMan::killPacMan()
{
	this->numberOfLifes--;
}