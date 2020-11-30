#include <iostream>
#include <SFML\Graphics.hpp>
#include "Engine.h";
#include "Ghost.h";

using namespace std;
using namespace sf;

Sprite Engine::drawObject(Object *object,String nameOfImage)
{
	Texture texture1;

	if (!texture1.loadFromFile(nameOfImage))
	{
		cout << "Cos poszlo nie tak - plik nie zosta³ otwarty\n";
		system("exit");
	}
	object->texture = texture1;
	Sprite picture(object->texture);
	return picture;
}

void Engine::display(RenderWindow *window)
{
	//Object *object = new Object();
	Ghost *ghost = new Ghost(0,0);
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}
	
		
		window->clear();
		window->draw(drawObject(ghost, "PacManGhost.jpg"));
		window->display();
	}
}

void Engine::startGame()
{
	RenderWindow window(VideoMode(640, 480), "Pac-Man");
	display(&window);

}