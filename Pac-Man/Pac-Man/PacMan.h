#ifndef PACMAN_H
#define PACMAN_H
#include "Ghost.h";

class PacMan : public Ghost
{
private:
	int numberOfLifes = 3;
public:
	PacMan(float posX = (50.0f), float posY = (60.0f), String nameOfFile = "PacManGhostRight.jpg");
	~PacMan();
	void killPacMan();
};

#endif