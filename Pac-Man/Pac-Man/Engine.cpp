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


void Engine::moveGhost(Sprite *player,int direction)
{
	float speed = 0.005f;

	player->move(speed, 0.00);

	switch (direction)
	{
	case 1:
	{
		player->move(speed, 0.00f);
		break;
	}
	case 2:
	{
		player->move(-speed, 0.00f);
		break;
	}
	default:
	{
		//player->move(speed, 0.00f);
		player->move(speed, speed);
	}
	}
}

void Engine::movePacMan(Map *map,Ghost *pacMan,Sprite *player)
{
	for (int y = 0; y <= (map->y_kafli) - 2; y++)
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
	}
	
	if ((pacMan->collision) == false)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			pacMan->setTexture("PacManGhostLeft.jpg");
			player->setTexture(pacMan->texture);
			player->move(-(pacMan->speed), 0.00f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			pacMan->setTexture("PacManGhostRight.png");
			player->setTexture(pacMan->texture);
			player->setRotation(0.0f);
			player->move((pacMan->speed), 0.00f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Up))
		{
			pacMan->setTexture("PacManGhostUP.jpg");
			player->setTexture(pacMan->texture);
			//player->setRotation(-90.0f);
			player->move(0.00f, -(pacMan->speed));
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Down))
		{
			pacMan->setTexture("PacManGhostDown.jpg");
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

void Engine::loadMap(Map *map)
{
	for (int y = 0; y <= (map->y_kafli) -1; y++)
	{
		for (int x = 0; x <= (map->x_kafli) - 1; x++)
		{
			if (x == 0 || y == 0 || x == ((map->x_kafli)-2) || y == ((map->y_kafli) - 2))
			{
				map->kafelek[x][y].setPosition((float)(x * (map->tile_width)), (float)(y * (map->tile_height)));
				map->kafelek[x][y].setTexture(map->wall);
				map->isWall[x][y] = true;
			}
		}
	}
}

void Engine::display(RenderWindow *window)
{
	Ghost *ghost = new Ghost();
	Ghost *ghost2 = new Ghost((220.0f),(120.0f),"blueGhost1.jpg");
	PacMan *pacMan = new PacMan(300.0f,360.0f,"pacManIcon.png");
	Food *food1 = new Food(5,"food.jpg");
	Food *food2 = new Food(5, "food.jpg");
	Food *food3 = new Food(5, "food.jpg");
	Food *food4 = new Food(5, "food.jpg");
	Food *food5 = new Food(5, "food.jpg");

	Image *image2 = new Image();
	image2->loadFromFile("PacManGhostRight.png");
	image2->createMaskFromColor(Color::Black);
	Sprite *sprite = new Sprite();
	
	
	
	food2->imageObject.setPosition(50.0f,80.0f);
	food3->imageObject.setPosition(50.0f,110.0f);
	food4->imageObject.setPosition(50.0f,140.0f);
	food5->imageObject.setPosition(50.0f,170.0f);
	
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
		window->clear(Color::White);
		for (int y = 0; y < (map->y_kafli) - 1; y++)
		{
			for (int x = 0; x < (map->x_kafli) - 1; x++)
			{
				window->draw(map->kafelek[x][y]);
			}
		}
		window->draw(food1->imageObject);
		window->draw(food2->imageObject);
		window->draw(food3->imageObject);
		window->draw(food4->imageObject);
		window->draw(food5->imageObject);
		window->draw(pacMan->imageObject);
		movePacMan(map,pacMan,&(pacMan->imageObject));
		window->draw(ghost->imageObject);
		moveGhost(&ghost->imageObject,1);
		window->draw(ghost2->imageObject);
		moveGhost(&ghost2->imageObject,2);
		window->display();
	}
}

void Engine::startGame()
{
	RenderWindow window(VideoMode(640, 460), "Pac-Man");
	display(&window);

}

void Engine::endGame()
{
	this->isRunning = false;
}