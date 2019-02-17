#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Player.h"
#include <iostream>
#include "Bullet.h"
#include <vector>
#include <algorithm>
#include <list>
#include "Enemy.h"
#include "ResourseLoader.h"

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "My window");

	
	ResourseLoader loader;

	loader.load("Actor.png");
	loader.load("Bullet.png");
	loader.load("NoTexture.png");

	Player player = Player(loader.getTextureByName("Actor.png"), 400, 300, -50);
	int cooldown = 0;
	int enemyOnScreen = 0;

	sf::Clock clock;
	std::list<Bullet> bulletList;
	std::list<Enemy> enemyList;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (player.deleted)
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
			
			while (enemyOnScreen <= 3)
			{
				enemyList.emplace_back(Enemy(loader.getTextureByName("Actor.png"), rand() % 800, rand() % 20, 0));
				enemyOnScreen++;
			}

			window.clear(sf::Color(244, 164, 96, 255));


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cooldown >= 200)
			{
				bulletList.push_back(player.shootBullet(loader.getTextureByName("Bullet.png")));
				cooldown = 0;
			}
			if (!bulletList.empty()) for (auto &bullet : bulletList)
			{
				window.draw(bullet.checkEveryFrame().sprite);
				for (auto &enemy : enemyList)
				{
					if (enemy.checkCollision(bullet))
					{
						enemy.deleted = true;
						bullet.deleted = true;
						enemyOnScreen--;
					}
				}
			}
			bulletList.remove_if([](Bullet n) { return n.deleted == true; });
			enemyList.remove_if([](Enemy n) { return n.deleted == true; });
			if (!enemyList.empty()) for (auto &enemy : enemyList)
			{
				enemy.runAI(player);
				window.draw(enemy.sprite);
				if (enemy.checkCollision(player)) player.deleted = true;
			}
			player.watchTarget(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			window.draw(player.sprite);
			window.display();
			clock.restart();
		}
	}

	return 0;
}