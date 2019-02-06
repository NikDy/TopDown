#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Player.h"
#include <iostream>

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "My window");
	
	Player player = Player("D:/SFML Project/TopDown/x64/Debug/Actor.png", 400, 300, -50);
	player.sprite.setOrigin(25, 25);

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
		player.WatchTarget(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		window.draw(player.sprite);
		window.display();

	}

	return 0;
}