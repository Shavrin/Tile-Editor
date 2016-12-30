#ifndef EDITORMODE_H
#define EDITORMODE_H

#define SIZE 20

#define WIDTH 640.f
#define HEIGHT 480.f


#include "Tile.h"
#include "SFML\Graphics.hpp"

class EditorMode {
private:
	Tile highlight;
	sf::Vector2i highlightedTile;
public:
	EditorMode();
	void render(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);


	



};



#endif // !EDITORMODE_H
