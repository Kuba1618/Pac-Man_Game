#include <iostream>
#include <SFML\Graphics.hpp>
#include "Engine.h";
#include "Ghost.h";

using namespace std;
using namespace sf;


void Engine::movePacMan(Sprite *player)
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

void Engine::display(RenderWindow *window)
{
	Ghost *ghost = new Ghost(50.0f,50.0f, "PacManGhost.jpg");
	Sprite ghostSprite(ghost->texture);
	ghostSprite.setPosition(ghost->posX,ghost->posY);
	
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
		movePacMan(&ghostSprite);
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