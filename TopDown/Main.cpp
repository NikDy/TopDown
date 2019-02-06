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
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			
		}

		if (clock.getElapsedTime().asMilliseconds() > 15.0f)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.GoSide(3);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.GoSide(1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.GoSide(7);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.GoSide(5);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player.GoSide(0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.GoSide(2);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player.GoSide(4);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.GoSide(6);
			player.WatchTarget(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			window.clear(sf::Color(244, 164, 96, 255));
			window.draw(player.sprite);
			window.display();
			clock.restart();
		}


	}

	return 0;
}