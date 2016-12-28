#pragma once
#include "SFML\Graphics.hpp"

class Game {
	
public:
	enum _gameState
	{
		pause,loading,playing
	};
	enum _gameMode
	{
		editorMode,Normal
	};

	_gameMode activeMode;
	_gameState activeState;
	sf::RectangleShape highlight;
	sf::Vector2i highlightedTile;
	Game() {
		highlight.setFillColor(sf::Color::Transparent);
		highlight.setOutlineColor(sf::Color::Green);
		highlight.setOutlineThickness(3);
		highlight.setOrigin(2, 1);
		highlight.setSize(sf::Vector2f(550.f / 18.f, 490.f / 18.f));
		activeMode = Normal;
	}
	void toggleMode() {
		if (activeMode == Normal) activeMode = editorMode;
		else activeMode = Normal;
	}

	void showGameMode() {

		switch (activeMode) {
		case Normal:
			std::cout << "Normal\n";
			break;
		case editorMode:
			std::cout << "editorMode\n";
			break;
		}
	}


	void highlightTile(sf::RenderWindow &window) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		for (int i = 0; i < 18; i++) {
			if (mousePos.x > i*(540.f / 18.f) && mousePos.x < (i+1)*(540.f/18.f)) {
				highlight.setPosition(i*(540.f / 18.f), highlight.getPosition().y);
				highlightedTile.x = i;
				break;
			}
		}
		for (int i = 0; i < 18; i++) {
			if (mousePos.y > i*(480.f / 18.f) && mousePos.y <(i + 1)*(480.f / 18.f)) {
				highlight.setPosition(highlight.getPosition().x, i*(480.f / 18.f));
				highlightedTile.y = i;

				break;

			}
		}
		window.draw(highlight);
		

	}

	void showMouseCoords(sf::RenderWindow &window) {
		std::cout << sf::Mouse::getPosition(window).x << "      " << sf::Mouse::getPosition(window).y << "     \n";
	}


	sf::Vector2i getHighlightedTile() {
		return highlightedTile;
	}

};