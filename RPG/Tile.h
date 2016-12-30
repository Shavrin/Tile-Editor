#pragma once

#ifndef TILE_H
#define TILE_H

#include "SFML\Graphics.hpp"

enum _tileType
{
	red, blue, green, yellow, magenta, alpha
};

class Tile {

private:
	sf::RectangleShape rectangle;

public:

	Tile() {}

	Tile(const sf::Color &color, sf::Vector2f &size) {
		rectangle.setFillColor(color);
		rectangle.setSize(size);
		rectangle.setOutlineThickness(3);
		rectangle.setOutlineColor(sf::Color::Black);
		
	}

	void draw(sf::RenderWindow &window) {
		window.draw(rectangle);
	}
	void setPosition(sf::Vector2f &position) {
		rectangle.setPosition(position);
	}
	void setOutlineThickness(float thickness) {
		rectangle.setOutlineThickness(thickness);
	}
	void setOutlineColor(const sf::Color &color) {
		rectangle.setOutlineColor(color);
	}
	sf::Vector2f getPosition() {
		return rectangle.getPosition();
	}
	void setOrigin(sf::Vector2f &origin) {
		rectangle.setOrigin(origin);
	}
	
};
#endif // !TILE_H
