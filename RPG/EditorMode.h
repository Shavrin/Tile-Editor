#ifndef EDITORMODE_H
#define EDITORMODE_H

#define SIZE 20

#define WIDTH 640.f
#define HEIGHT 480.f


#include "Tile.h"
#include "World.h"
#include "SFML\Graphics.hpp"

class EditorMode {
private:
	Tile highlight;
	sf::Vector2i highlightedTile;
	bool mouseButtonPressedL;
	bool mouseButtonPressedR;
public:
	EditorMode();
	void render(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);

	void handleInput(World &world,sf::Mouse::Button button,bool isPressed);
	void incrementTile(World &world);
	void decrementTile(World &world);

	



};



#endif // !EDITORMODE_H
