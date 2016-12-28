#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include <fstream>

#include <iostream>
#include <random>

class World {
public:
	enum _tileType
	{
		red,blue,green,yellow
	};

	_tileType mapTiles[18][18];
	
	std::fstream tilesFile;
	
	sf::RectangleShape tileBlue, tileGreen, tileYellow, tileRed;
	World() {
		tileBlue.setFillColor(sf::Color::Blue);
		tileRed.setFillColor(sf::Color::Red);
		
		tileGreen.setFillColor(sf::Color::Green);
		tileYellow.setFillColor(sf::Color::Yellow);
		
		tileBlue.setSize(sf::Vector2f(540 / 18, 480.f/ 18.f));

		tileRed.setSize(sf::Vector2f(540 / 18, 480.f / 18.f));
		tileYellow.setSize(sf::Vector2f(540 / 18, 480.f / 18.f));
		tileGreen.setSize(sf::Vector2f(540 / 18, 480.f / 18.f));

		//randomize();

	}
	void randomize() {
		tilesFile.open("tiles.txt");
		std::random_device generator;
		std::uniform_int_distribution<int> distribution(0, 3);
		int currTile;
		for (int i = 0; i < 18; i++) {
			for (int j = 0; j < 18; j++) {
				currTile = distribution(generator);
				tilesFile << currTile;
				tilesFile << " ";
			}
			if(i != 17)
			tilesFile << "\n";
			
		}
		tilesFile.close();
		showMapTiles();
	}
	void showMapTiles() {
		for (int i = 0; i < 18;i++) {
			for (int j = 0; j < 18; j++) {
				std::cout << mapTiles[i][j];
			}
			std::cout << "\n";
		}
		std::cout << "\n";

	}
	void isOpen() {
		
		if (tilesFile.is_open()) {
			std::cout << "Otwarty!";
		}
		else std::cout << "Zamkniety!";
	}
	void loadFromFile() {
		tilesFile.open("tiles.txt",std::ios::in);
		if (tilesFile.is_open()) {
			
			int currNumber;
			char currChar;
			int lineNumber = 0;
			int counter = 0;
			while(!tilesFile.eof()){
				if (counter >= 18) { counter = 0; lineNumber++; }
				tilesFile >> currChar;
				currNumber = currChar - '0';

				mapTiles[counter][lineNumber] = (World::_tileType)currNumber;
				counter++;

			
			
			}
			tilesFile.close();
		}
		else std::cout << "Couldn't open file\n";

	}

	void initialize() {
		
	}

	
	void draw(sf::RenderWindow &window) {

		float width = 540 / 18;
		float height = 480.f / 18.f;
		for (int i = 0; i < 18; i++) {
			for (int j = 0; j < 18; j++) {
				switch (mapTiles[i][j]) {
				case blue:
					tileBlue.setPosition(sf::Vector2f(i * width,j * height));
					window.draw(tileBlue);
					break;
				case red:
					tileRed.setPosition(sf::Vector2f(i * width, j * height));
					window.draw(tileRed);
					break;
				case yellow:
					tileYellow.setPosition(sf::Vector2f(i * width, j * height));
					window.draw(tileYellow);
					break;
				case green:
					tileGreen.setPosition(sf::Vector2f(i * width, j * height));
					window.draw(tileGreen);
					break;
				}
			}
		}
	}

	

};