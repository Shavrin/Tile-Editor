#include <iostream>
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"

#include "world.h"
#include "game.h"
#include <Windows.h>




int main() {

	Game game;
	
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
					gotoxy(0, 2);

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
				if (mainEvent.key.code == sf::Keyboard::R) {
					world.randomize();
				}
				if (mainEvent.key.code == sf::Keyboard::S) {
					game.toggleMode();
					game.showGameMode();
				}
				
				if (mainEvent.key.code == sf::Keyboard::K) {
					gotoxy(0, 2);
					world.showMapTiles();

				}
				if (mainEvent.key.code == sf::Keyboard::M) {
					gotoxy(15, 0);
					world.incrementTile(game.getHighlightedTile().x, game.getHighlightedTile().y);
					world.loadFromFile();
					gotoxy(0, 2);

					world.showMapTiles();
				}

			}
		}
		


		mainWindow.clear(sf::Color::Magenta);

		world.draw(mainWindow);
		if (game.activeMode == Game::editorMode) {
		

			game.highlightTile(mainWindow);
			gotoxy(15, 2);
			std::cout<<"CurrTile: X:"<<game.getHighlightedTile().x<<"    "<< game.getHighlightedTile().y<<"     \n";
		
		}

		mainWindow.display();

	}

	return EXIT_SUCCESS;
}