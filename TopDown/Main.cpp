#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Player.h"
#include <iostream>
#include "Bullet.h"
#include <vector>
#include <algorithm>
#include <list>
#include "Enemy.h"

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "My window");
	
	Player player = Player("D:/SFML Project/TopDown/x64/Debug/Actor.png", 400, 300, -50);
	Enemy enemy = Enemy("D:/SFML Project/TopDown/x64/Debug/Actor.png", 400, 300, -50);
	Enemy enemy2 = Enemy("D:/SFML Project/TopDown/x64/Debug/Actor.png", 100, 200, -50);
	int cooldown = 0;

	sf::Clock clock;
	std::list<Bullet> bulletList;


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
			cooldown += 15;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.goSide(3);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.goSide(1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.goSide(7);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.goSide(5);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player.goSide(0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.goSide(2);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player.goSide(4);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.goSide(6);
			



			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cooldown >= 200)
			{
				bulletList.push_back(player.shootBullet());
				cooldown = 0;
			}
			bulletList.remove_if([](Bullet n) { return n.deleted == true; });
			window.clear(sf::Color(244, 164, 96, 255));
			if (!bulletList.empty()) for (auto &bullet : bulletList)
			{
				window.draw(bullet.checkEveryFrame().sprite);
				if (enemy.checkCollision(bullet))
					window.draw(enemy2.sprite);
			}
			//enemy.runAI(player);
			player.watchTarget(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			
			window.draw(player.sprite);
			window.draw(enemy.sprite);
			window.display();
			clock.restart();
		}
	}

	return 0;
}