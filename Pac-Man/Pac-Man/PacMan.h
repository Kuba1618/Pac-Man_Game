#ifndef PACMAN_H
#define PACMAN_H
#include "Ghost.h";

class PacMan : public Ghost
{
private:
	int numberOfLifes = 3;
public:
	PacMan(float posX = (50.0F), float posY = (60.0F), String nameOfFile = "PacManGhostRight.jpg");
	~PacMan();
	void killPacMan();
};

#endif