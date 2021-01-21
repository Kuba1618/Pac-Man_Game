#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Engine.h"

using namespace std;
using namespace sf;

void Engine::collisionPacManGhost(PacMan *pacMan1, Ghost *ghost1,Results *results)
{
	pacMan1->movePacMan();
	if (pacMan1->imageObject.getGlobalBounds().intersects(ghost1->imageObject.getGlobalBounds()))
	{
		
		pacMan1->collision = true;
		pacMan1->imageObject.setPosition(80.0f,80.0f);
		results->lostLife();
		results->showResult();
	}
}

void Engine::collisionPacManFood(PacMan *pacMan1, Food *food1,Map *map, Results *results)
{
	if (pacMan1->imageObject.getGlobalBounds().intersects(food1->imageObject.getGlobalBounds()))
	{
		results->eatFood();
		results->showResult();
		map->tiles[(int)food1->imageObject.getPosition().x/40][(int)food1->imageObject.getPosition().y/40] = NULL;
		delete food1;
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
	Results *results = new Results();
	Ghost *ghost = new Ghost((220.0f), (80.0f), 0.13f, "orangeGhost.png", 0); 
	Ghost *ghost2 = new Ghost((80.0f), (200.0f), 0.13f, "blueGhost.png", 2);
	PacMan *pacMan = new PacMan((300.0f), (360.0f), 0.06f, "pacManIcon.png");
		
	Map *map = new Map();
	map->fillKindOfTilesArray();
	map->loadMap();
	map->allGhosts.push_back(ghost);
	map->allGhosts.push_back(ghost2);
	
	Music song,intro,death;
	if (!song.openFromFile("../../Music/VitaminC_Graduation.wav"))
	{
		cout << "Blad podczas ladowania muzyki" << endl;
	}
	if (!intro.openFromFile("../../Music/intro.wav"))
	{
		cout << "Blad podczas ladowania muzyki" << endl;
	}
	if (!death.openFromFile("../../Music/death.wav"))
	{
		cout << "Blad podczas ladowania muzyki" << endl;
	}
	//intro.play();
	//song.play();
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
			collisionPacManGhost(pacMan, gh,results);
		}
		for (Food *fd : map->allFood)
		{
			collisionPacManFood(pacMan, fd, map,results);
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