#include <iostream>
#include <SFML\Graphics.hpp>
#include "Engine.h";
#include "Ghost.h";
#include "Brick.h";
#include "PacMan.h";
#include "Map.h";

using namespace std;
using namespace sf;


void Engine::moveGhost(Sprite *player)
{
	float speed = 0.09f;
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		player->move(-speed, 0.00f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		player->move(speed, 0.00);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		player->move(0.00f, -speed);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		player->move(0.00f, speed);
	}
}
void Engine::movePacMan(Ghost *pacMan,Sprite *player)
{
	float speed = 0.09f;
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		pacMan->setTexture("PacManGhostLeft.jpg");
		player->setTexture(pacMan->texture);
		player->move(-speed, 0.00f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		pacMan->setTexture("PacManGhostRight.jpg");
		player->setTexture(pacMan->texture);
		player->setRotation(0.0f);
		player->move(speed, 0.00f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		pacMan->setTexture("PacManGhostUP.jpg");
		player->setTexture(pacMan->texture);
		//player->setRotation(-90.0f);
		player->move(0.00f, -speed);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		pacMan->setTexture("PacManGhostDown.jpg");
		player->setTexture(pacMan->texture);
		player->move(0.00f, speed);
	}
}

void Engine::loadMap(Map *map)
{
	for (int y = 0; y <= (map->y_kafli) -1; y++)
	{
		for (int x = 0; x <= (map->x_kafli) - 1; x++)
		{
			if (x == 0 || y == 0)
			{
				map->kafelek[x][y].setPosition((float)(x * (map->tile_width)), (float)(y * (map->tile_height)));
				map->kafelek[x][y].setTexture(map->wall);
				map->isWall[x][y] = 1;
			}
		}
	}
}

void Engine::display(RenderWindow *window)
{
	//Ghost *ghost = new Ghost();
	PacMan *ghost = new PacMan();
		
	Brick *brick1 = new Brick();
	Sprite brickObject(brick1->texture);

	Map *map = new Map();
	loadMap(map);

	while (window->isOpen() && isRunning)
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}		
		window->clear();
		for (int y = 0; y < (map->y_kafli) - 1; y++)
		{
			for (int x = 0; x < (map->x_kafli) - 1; x++)
			{
				window->draw(map->kafelek[x][y]);
			}
		}
		window->draw(ghost->imageObject);
		movePacMan(ghost,&(ghost->imageObject));
		window->draw(brickObject);
		window->display();
	}
}

void Engine::startGame()
{
	RenderWindow window(VideoMode(640, 480), "Pac-Man");
	display(&window);

}

void Engine::endGame()
{
	this->isRunning = false;
}