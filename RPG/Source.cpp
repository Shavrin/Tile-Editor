#include <iostream>

#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"


int main() {
	sf::RenderWindow mainWindow(sf::VideoMode(540, 480), "RPG");
	sf::View view;
	view.setCenter(540 / 2, 480 / 2);
	view.setSize(540 / 4, 480 / 4);

	while (mainWindow.isOpen()) {
		sf::Event mainEvent;
		sf::RectangleShape redRect(sf::Vector2f(50, 50));
		redRect.setFillColor(sf::Color::Red);
		redRect.setPosition(540 / 2, 480 / 2);
		
		mainWindow.setView(view);

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