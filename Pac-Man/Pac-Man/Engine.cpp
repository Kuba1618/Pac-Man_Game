#include <iostream>
#include <SFML\Graphics.hpp>
#include "Engine.h";
#include "Ghost.h";
#include "Brick.h";
#include "PacMan.h";
#include "Map.h";
#include "Food.h";

using namespace std;
using namespace sf;


void Engine::moveGhost(Sprite *player,Ghost *ghost,int direction)
{

	switch (direction)
	{
	case 1:
	{
		player->move(ghost->speed, 0.00f);
		break;
	}
	case 2:
	{
		player->move(-(ghost->speed), 0.00f);
		break;
	}
	default:
	{
		player->move(ghost->speed, ghost->speed);
	}
	}
}

void Engine::movePacMan(Map *map,Ghost *pacMan,Sprite *player)
{
	/*for (int y = 0; y <= (map->y_kafli) - 2; y++)
	{
		for (int x = 0; x <= (map->x_kafli) - 2; x++)
		{
			if (pacMan->imageObject.getPosition().x + (map->tile_width) == map->kafelek[x][y].getPosition().x
				&& pacMan->imageObject.getPosition().y + (map->tile_height) == (map->kafelek[x][y]).getPosition().y)
				//&& map->isWall[x][y] == 1)
			{
				pacMan->collision = true;
			}
		}
	}*/
	
	if ((pacMan->collision) == false)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			pacMan->setTexture("pacManIconLeft.png");
			player->setTexture(pacMan->texture);
			player->move(-(pacMan->speed), 0.00f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			pacMan->setTexture("pacManIcon.png");
			player->setTexture(pacMan->texture);
			player->setRotation(0.0f);
			player->move((pacMan->speed), 0.00f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up))
		{
			pacMan->setTexture("pacManIconUp.png");
			player->setTexture(pacMan->texture);
			player->move(0.00f, -(pacMan->speed));
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down))
		{
			pacMan->setTexture("pacManIconDown.png");
			player->setTexture(pacMan->texture);
			player->move(0.00f, (pacMan->speed));
		}
	}
}

/*
void Engine::moveObject(Ghost *ghost, Map *map)
{
	bool kolizja = false;

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		for (int y = 0; y <= (map->y_kafli) - 1; y++)
		{
			for (int x = 0; x <= (map->x_kafli) - 1; x++)
			{
				if (ghost->imageObject.getPosition().x + map->tile_width == map->kafelek[x][y].getPosition().x
					&& ghost->imageObject.getPosition().y + map->tile_height == (map->kafelek[x][y]).getPosition().y
					&& map->isWall[x][y] == 1)
					kolizja = true;
			}
		}
		if (kolizja != true)
		{
			if (ghost->pacMan)
			{
				movingPacMan();
			}
			else if (!ghost->pacMan)
			{
				movingGhost();
			}
			
		}

	}
}*/

void Engine::display(RenderWindow *window)
{
	Ghost *ghost = new Ghost();
	Ghost *ghost2 = new Ghost((220.0f),(120.0f),0.03f,"blueGhost.png");
	PacMan *pacMan = new PacMan((300.0f),(360.0f),0.06f,"pacManIcon.png");
		
	Map *map = new Map();
	map->fillIsWall();
	map->loadMap();
	
	
	while(window->isOpen() && isRunning)
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}		
		window->clear(Color::Black);
		map->displayMap(window);
		window->draw(pacMan->imageObject);
		movePacMan(map,pacMan,&(pacMan->imageObject));
		window->draw(ghost->imageObject);
		moveGhost(&ghost->imageObject,ghost,1);
		window->draw(ghost2->imageObject);
		moveGhost(&ghost2->imageObject,ghost2,2);
		window->display();
	}
	system("pause");
}

void Engine::startGame()
{
	RenderWindow window(VideoMode(660, 480), "Pac-Man");
	display(&window);
}

void Engine::endGame()
{
	this->isRunning = false;
}