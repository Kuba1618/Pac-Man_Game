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
		Music hitGhost;
		if (!hitGhost.openFromFile("../../Music/Ghost.wav"))
		{
			cout << "Blad podczas ladowania muzyki" << endl;
		}
		pacMan1->collision = true;
		hitGhost.setPitch(1.5f);
		hitGhost.play();
		pacMan1->imageObject.setPosition(280.0f,540.0f);
		results->lostLife();
		results->showResult();
		Sleep(382);
	}
}

void Engine::collisionPacManFood(PacMan *pacMan1, Food *food1,Map *map, Results *results)
{
	if (pacMan1->imageObject.getGlobalBounds().intersects(food1->imageObject.getGlobalBounds()))
	{
		Music fruit;
		if (!fruit.openFromFile("../../Music/Fruit.wav"))
		{
			cout << "Blad podczas ladowania muzyki" << endl;
		}
		fruit.setPitch(1.5f);
		fruit.play();
		results->eatFood();
		results->showResult();
		map->tiles[(int)food1->imageObject.getPosition().x/40][(int)food1->imageObject.getPosition().y/40] = NULL;
		delete food1;
		Sleep(50);
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
	PacMan *pacMan = new PacMan((300.0f), (360.0f), 0.5f, "pacManIcon.png");
		
	Map *map = new Map();
	map->fillKindOfTilesArray();
	map->loadMap();
	map->loadGhost(3, 1, "orangeGhost.png",0);
	map->loadGhost(2, 9, "blueGhost.png",0);
	map->loadGhost(5, 5, "orangeGhost.png", 2);
	map->loadGhost(11, 5, "blueGhost.png",2);
	map->loadGhost(16, 6, "orangeGhost.png",0);
	Music intro;
	if (!intro.openFromFile("../../Music/intro.wav"))
	{
		cout << "Blad podczas ladowania muzyki" << endl;
	}
	intro.play();
	
	
	while (window->isOpen() && isRunning)
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}
		if (results->numberOfLife == 0)
		{
			isRunning = false;
		}
		window->clear(Color::Black);
		map->displayMap(window);
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
			gh->moveGhost(gh->currentDirection);
			for (Brick *bk : map->allBricks)
			{
				collisionGhostBricks(gh,bk);
			}
		}
		window->display();
	}
		
	
	
		Music death;
		if (!death.openFromFile("../../Music/Death.wav"))
		{
			cout << "Blad podczas ladowania muzyki" << endl;
		}
		death.play();

		/*RenderWindow gameOverWindow(VideoMode(300, 150), "Game Over");
		while (gameOverWindow.isOpen())
		{
			Event event;
			while (window->pollEvent(event))
			{
				if (event.type == Event::Closed)
					window->close();
			}
			gameOverWindow.clear(Color::Black);
			window->display();
		}*/
		
		Sleep(1700);
		window->close();
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