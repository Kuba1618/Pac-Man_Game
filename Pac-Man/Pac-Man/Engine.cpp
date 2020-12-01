#include <iostream>
#include <SFML\Graphics.hpp>
#include "Engine.h";
#include "Ghost.h";
#include "Brick.h";

using namespace std;
using namespace sf;


void Engine::moveGhost(Sprite *player)
{
	float speed = 0.09;
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		player->move(-speed, 0.00);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		player->move(speed, 0.00);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		player->move(0.00, -speed);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		player->move(0.00, speed);
	}
}
void Engine::movePacMan(Ghost *pacMan,Sprite *player)
{
	float speed = 0.09;
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		pacMan->setTexture("PacManGhostLeft.jpg");
		player->setTexture(pacMan->texture);
		player->move(-speed, 0.00);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		pacMan->setTexture("PacManGhostRight.jpg");
		player->setTexture(pacMan->texture);
		player->setRotation(0.0f);
		player->move(speed, 0.00);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		pacMan->setTexture("PacManGhostUP.jpg");
		player->setTexture(pacMan->texture);
		//player->setRotation(-90.0f);
		player->move(0.00, -speed);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		pacMan->setTexture("PacManGhostDown.jpg");
		player->setTexture(pacMan->texture);
		player->move(0.00, speed);
	}
}

void Engine::display(RenderWindow *window)
{
	Ghost *ghost = new Ghost(50.0f,50.0f,"PacManGhostRight.jpg");
	Sprite ghostSprite(ghost->texture);
	ghostSprite.setPosition(ghost->posX,ghost->posY);
	
	Brick *brick1 = new Brick();
	Sprite brickObject(brick1->texture);

	while (window->isOpen() && isRunning)
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}		
		window->clear();
		window->draw(ghostSprite);
		movePacMan(ghost,&ghostSprite);
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