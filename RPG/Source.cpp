#include <iostream>

#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"


int main() {
	sf::RenderWindow mainWindow(sf::VideoMode(540, 480), "RPG");


	while (mainWindow.isOpen()) {
		sf::Event mainEvent;
		sf::RectangleShape redRect(sf::Vector2f(50, 50));
		redRect.setFillColor(sf::Color::Red);
		redRect.setPosition(540 / 2, 480 / 2);
		

		while (mainWindow.pollEvent(mainEvent)) {
			switch (mainEvent.type) {
			case sf::Event::Closed:
				mainWindow.close();
			}
		}
		
		mainWindow.clear(sf::Color::Magenta);
		mainWindow.draw(redRect);
		
		
		
		mainWindow.display();

	}

	return EXIT_SUCCESS;
}