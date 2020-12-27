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
void Engine::collision(Ghost *ghost1, Ghost *ghost2)
{
	if (ghost1->imageObject.getGlobalBounds().intersects(ghost2->imageObject.getGlobalBounds()))
	{
		cout << "Kolizja!!!\n";
	}
}

void Engine::collisionOfFood(Ghost *object1, Food *object2)
{
	if (object1->imageObject.getGlobalBounds().intersects(object2->imageObject.getGlobalBounds()))
	{
		cout << "Kolizja!!!\n";
	}
}

void Engine::collisionOfBricks(Ghost *object1, Brick *object2)
{
	if (object1->imageObject.getGlobalBounds().intersects(object2->imageObject.getGlobalBounds()))
	{
		cout << "Kolizja!!!\n";
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
	
	vector<int>::iterator pos;
	
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
		//map->moveGhosts();
		window->draw(ghost->imageObject);
		ghost->moveGhost(1);
		window->draw(ghost2->imageObject);
		ghost2->moveGhost(2);
		window->draw(pacMan->imageObject);
		pacMan->movePacMan();
		//collision(pacMan, ghost2); //DO NOT DELETE - until the code below will be ready to go on every ghost
		for (Ghost *gh : map->allGhosts)
		{
			collision(pacMan, gh);
		}
		for (Food *fd : map->allFood)
		{
			collisionOfFood(pacMan, fd);
		}
		for (Brick *bk : map->allBricks)
		{
			collisionOfBricks(pacMan, bk);
		}
		/*for (Ghost *g : map->allGhosts)
		{
			g->moveGhost(2);
		}*/
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