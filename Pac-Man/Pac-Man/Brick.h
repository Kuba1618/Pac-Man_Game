#ifndef BRICK_H
#define BRICK_H

#include "Object.h";

class Brick : public Object 
{
public:
	const int width = 30;
	const int height = 30;
	Brick(String nameOfImage = "brick2.jpg");
};

#endif
