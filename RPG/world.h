#pragma once
#include "SFML\Graphics.hpp"
#include <vector>
#include <fstream>

#include <iostream>
#include <random>
#include <Windows.h>
void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}

class World {
public:
	enum _tileType
	{
		red,blue,green,yellow,magenta,alpha
	};

	_tileType mapTiles[18][18];
	
	std::fstream tilesFile;
	
	sf::RectangleShape tileBlue, tileGreen, tileYellow, tileRed,tileMagenta,tileAlpha;
	World() {
		tileBlue.setFillColor(sf::Color::Blue);
		tileRed.setFillColor(sf::Color::Red);
		
		tileGreen.setFillColor(sf::Color::Green);
		tileYellow.setFillColor(sf::Color::Yellow);
		
		tileMagenta.setFillColor(sf::Color::Magenta);
		tileAlpha.setFillColor(sf::Color(255,255,255,100));

		tileBlue.setOutlineThickness(2);
		tileRed.setOutlineThickness(2);

		tileGreen.setOutlineThickness(2);
		tileYellow.setOutlineThickness(2);

		tileMagenta.setOutlineThickness(2);
		tileAlpha.setOutlineThickness(2);

		tileBlue.setOutlineColor(sf::Color::Black);
		tileRed.setOutlineColor(sf::Color::Black); 

		tileGreen.setOutlineColor(sf::Color::Black);
		tileYellow.setOutlineColor(sf::Color::Black);

		tileMagenta.setOutlineColor(sf::Color::Black);
		tileAlpha.setOutlineColor(sf::Color::Black);


		tileBlue.setSize(sf::Vector2f(540 / 18, 480.f/ 18.f));

		tileRed.setSize(sf::Vector2f(540 / 18, 480.f / 18.f));
		tileYellow.setSize(sf::Vector2f(540 / 18, 480.f / 18.f));
		tileGreen.setSize(sf::Vector2f(540 / 18, 480.f / 18.f));


		tileMagenta.setSize(sf::Vector2f(540 / 18, 480.f / 18.f));
		tileAlpha.setSize(sf::Vector2f(540 / 18, 480.f / 18.f));

		//randomize();

	}
	void randomize() {
		tilesFile.open("tiles.txt");
		std::random_device generator;
		std::uniform_int_distribution<int> distribution(0, 5);
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
	}
	void showMapTiles() {
		for (int i = 0; i < 18;i++) {
			for (int j = 0; j < 18; j++) {
				std::cout << mapTiles[j][i];
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
		tilesFile.open("tiles.txt");
		tilesFile.clear();
		tilesFile.seekg(0, std::ios::beg);
		if (tilesFile.is_open()) {
			
			int currNumber;
			char currChar;
			int lineNumber = 0;
			int counter = 0;
			while(!tilesFile.eof()){
				if (counter > 17) { counter = 0; lineNumber++; }
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
	//TO UNDERSTAND


	void incrementTile(int X, int Y) {
		
		tilesFile.clear();
		tilesFile.seekp(0, std::ios::beg);


		std::string currLine;
		
		tilesFile.open("tiles.txt");


		int number = 0;
		for (int i = 0; i < Y*18; i++) {
			tilesFile >> number;
		}
		for (int i = 0; i < X+1; i++) {
			tilesFile >> number;

		}
		if (number == 5) number = 0;
		else number++;

		tilesFile.clear();
		tilesFile.seekp(-1, std::ios::cur);

		std::cout << "position in file: " << tilesFile.tellp();
		tilesFile << number;

		std::cout << "position in file: " << tilesFile.tellp();


		gotoxy(15,0);

		

		tilesFile.close();
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
				case magenta:
					tileMagenta.setPosition(sf::Vector2f(i*width, j*height));
					window.draw(tileMagenta);
					break;
				case alpha:
					tileAlpha.setPosition(sf::Vector2f(i*width, j*height));
					window.draw(tileAlpha);
					break;
				}
			}
		}
	}

	

};