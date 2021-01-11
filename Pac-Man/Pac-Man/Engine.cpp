#include <iostream>
#include <SFML\Graphics.hpp>
#include "Engine.h";

using namespace std;
using namespace sf;

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
		//Sprite black;
		//cout<<"Zwroc x= "<<(int)food1->imageObject.getPosition().x<<"  " <<(int)food1->imageObject.getPosition().y;
		map->tiles[((int)food1->imageObject.getPosition().x)/22][((int)food1->imageObject.getPosition().y)/16] = NULL;
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
	//ghost1->collision = false;
}

void Engine::display(RenderWindow *window)
{
	Ghost *ghost = new Ghost((120.0f), (200.0f), 0.03f, "orangeGhost.png", 1);
	Ghost *ghost2 = new Ghost((220.0f),(120.0f),0.03f,"blueGhost.png",2);
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
		ghost->moveGhost(ghost->currentDirection);
		window->draw(ghost2->imageObject);
		ghost2->moveGhost(ghost2->currentDirection);
		window->draw(pacMan->imageObject);
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