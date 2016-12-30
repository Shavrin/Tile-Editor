#pragma once




#include "World.h"
#include <string>
#include <fstream>
#include <iostream>
#include <random>
void World::loadFromFile(std::string &filename) {

	std::ifstream file;
	int temp = 0;
	file.open(filename);

	if (file.is_open()) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				file >> temp;
				mapTiles[i][j] = temp;
			}
			}




		file.close();
	}
	else std::cout << "Loading from file error \n";
}
void World::saveToFile(std::string &filename) {
	std::ofstream file(filename);

	if (file.is_open()) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				file << mapTiles[i][j] << " ";
			}
			file << "\n";
		}
		file.close();
		
	}
	else std::cout << "Save to file ERROR\n";

}

World::World() {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			mapTiles[i][j] = 0;
		}
		}

	Blue = Tile(sf::Color::Blue, sf::Vector2f(WIDTH / SIZE, HEIGHT / SIZE));
	Green = Tile(sf::Color::Green, sf::Vector2f(WIDTH / SIZE, HEIGHT / SIZE));
	Yellow = Tile(sf::Color::Yellow, sf::Vector2f(WIDTH / SIZE, HEIGHT / SIZE));
	Alpha = Tile(sf::Color(0, 0, 0, 100), sf::Vector2f(WIDTH / SIZE, HEIGHT / SIZE));
	Magenta = Tile(sf::Color::Magenta, sf::Vector2f(WIDTH / SIZE, HEIGHT / SIZE));
	Red = Tile(sf::Color::Red, sf::Vector2f(WIDTH / SIZE, HEIGHT / SIZE));

	


}

void World::draw(sf::RenderWindow &window) {

	sf::Vector2f position(WIDTH / SIZE, HEIGHT / SIZE);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j <	SIZE; j++) {
			switch (mapTiles[i][j]) {
			case blue:
				Blue.setPosition(sf::Vector2f(position.x * i, position.y*j));
				Blue.draw(window);
				break;
			case red:
				Red.setPosition(sf::Vector2f(position.x * i, position.y*j));
				Red.draw(window);
				break;
			case alpha:
				Alpha.setPosition(sf::Vector2f(position.x * i, position.y*j));
				Alpha.draw(window);
				break;
			case green:
				Green.setPosition(sf::Vector2f(position.x * i, position.y*j));
				Green.draw(window);
				break;
			case yellow:
				Yellow.setPosition(sf::Vector2f(position.x * i, position.y*j));
				Yellow.draw(window);
				break;
			case magenta:
				Magenta.setPosition(sf::Vector2f(position.x * i, position.y*j));
				Magenta.draw(window);
				break;
			}
			}
			}
}




void World::randomizeMapTiles() {
	std::random_device numberGenerator;
	std::uniform_int_distribution<int> numberDistribution(0, 5);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			mapTiles[i][j] = numberDistribution(numberGenerator);
			
		}
		}

}

