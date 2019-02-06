#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Entity.h"

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "My window");
	
	Entity player = Entity("D:/SFML Project/TopDown/x64/Debug/Actor.png", 50, 50);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::D)
				{
					player.GoSide(0);
				}
			}
		}


		window.clear();
		window.draw(player.sprite);
		window.display();

	}

	return 0;
}