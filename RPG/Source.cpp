#include <iostream>
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"

#include "world.h"

int main() {
	sf::RenderWindow mainWindow(sf::VideoMode(540, 480), "RPG");

	World world;
	sf::View view0(sf::Vector2f(540.f / 2.f, 480.f / 2.f), sf::Vector2f(540.f, 480.f));

	sf::View view1(sf::Vector2f(540.f/4.f,480.f/4.f), sf::Vector2f(540.f / 2.f, 480.f / 2.f));
	sf::View view2(sf::Vector2f(3*540.f / 4.f,480.f / 4.f), sf::Vector2f(540.f / 2.f, 480.f / 2.f));
	sf::View view3(sf::Vector2f(540.f / 4.f, 480.f*3 / 4.f), sf::Vector2f(540.f / 2.f, 480.f / 2.f));
	sf::View view4(sf::Vector2f(540.f*3 / 4.f, 480.f*3 / 4.f), sf::Vector2f(540.f / 2.f, 480.f / 2.f));

	while (mainWindow.isOpen()) {
		sf::Event mainEvent;


		while (mainWindow.pollEvent(mainEvent)) {
			switch (mainEvent.type) {
			case sf::Event::Closed:
				mainWindow.close();
				break;

			case sf::Event::KeyPressed:
				if (mainEvent.key.code == sf::Keyboard::L) {
					//world.randomize();

					world.loadFromFile();
					world.showMapTiles();
				}
				if (mainEvent.key.code == sf::Keyboard::Escape) {
					mainWindow.close();
				}

				if (mainEvent.key.code == sf::Keyboard::Num0) {
					mainWindow.setView(view0);
				}
				if (mainEvent.key.code == sf::Keyboard::Num4) {
					mainWindow.setView(view4);
				}
				
				if (mainEvent.key.code == sf::Keyboard::Num3) {
					mainWindow.setView(view3);

				}
				if (mainEvent.key.code == sf::Keyboard::Num2) {
					mainWindow.setView(view2);

				}
				if (mainEvent.key.code == sf::Keyboard::Num1) {
					mainWindow.setView(view1);

				}
			}
		}
		
		mainWindow.clear(sf::Color::Magenta);
		
		world.draw(mainWindow);
		
		mainWindow.display();

	}

	return EXIT_SUCCESS;
}