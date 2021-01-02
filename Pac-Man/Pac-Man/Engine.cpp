#include <iostream>
#include <SFML\Graphics.hpp>
#include "Engine.h";

using namespace std;
using namespace sf;

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
void Engine::collisionPacManGhost(PacMan *pacMan1, Ghost *ghost1)
{
	pacMan1->movePacMan();
	if (pacMan1->imageObject.getGlobalBounds().intersects(ghost1->imageObject.getGlobalBounds()))
	{
		pacMan1->collision = true;
	}
}

void Engine::collisionPacManFood(PacMan *pacMan1, Food *food1,Map *map)
{
	if (pacMan1->imageObject.getGlobalBounds().intersects(food1->imageObject.getGlobalBounds()))
	{
		cout << "Kolizja z jedzeniem!!!\n";
		delete food1;
		//food1 = NULL;
	}
}

void Engine::collisionPacManBricks(Ghost *pacMan1, Brick *brick1)
{
	if (pacMan1->imageObject.getGlobalBounds().intersects(brick1->imageObject.getGlobalBounds()))
	{
		pacMan1->collision = true;
	}
}

void Engine::collisionGhostBricks(Ghost *ghost1, Brick *brick1)
{
	if (ghost1->imageObject.getGlobalBounds().intersects(brick1->imageObject.getGlobalBounds()))
	{
		ghost1->collision = true;
	}
}

void Engine::display(RenderWindow *window)
{
	Ghost *ghost = new Ghost();
	Ghost *ghost2 = new Ghost((220.0f),(120.0f),0.03f,"blueGhost.png");
	PacMan *pacMan = new PacMan((300.0f), (360.0f), 0.06f, "pacManIcon.png");
		
	Map *map = new Map();
	map->fillKindOfTilesArray();
	map->loadMap();
	map->allGhosts.push_back(ghost);
	map->allGhosts.push_back(ghost2);
	
	while (window->isOpen() && isRunning)
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}
		window->clear(Color::Black);
		map->displayMap(window);
		window->draw(ghost->imageObject);
		ghost->moveGhost(1);
		window->draw(ghost2->imageObject);
		ghost2->moveGhost(2);
		window->draw(pacMan->imageObject);
		//pacMan->movePacMan();
		for (Ghost *gh : map->allGhosts)
		{
			collisionPacManGhost(pacMan, gh);
		}
		for (Food *fd : map->allFood)
		{
			collisionPacManFood(pacMan, fd, map);
		}
		for (Brick *bk : map->allBricks)
		{
			collisionPacManBricks(pacMan, bk);
		}
		for (Ghost *gh : map->allGhosts)
		{
			for (Brick *bk : map->allBricks)
			{
				collisionGhostBricks(gh,bk);
			}
		}
		window->display();
	}
	//map->showkindOfTiles();
	system("pause");
}

void Engine::startGame()
{
	RenderWindow window(VideoMode(880, 640), "Pac-Man");
	display(&window);
}

void Engine::endGame()
{
	this->isRunning = false;
}