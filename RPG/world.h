#ifndef WORLD_H
#define WORLD_H

#define SIZE 20

#define WIDTH 640.f
#define HEIGHT 480.f

#include "Tile.h"

#include "SFML\Graphics.hpp"
#include <array>




class World {


private:

	int mapTiles[SIZE][SIZE];

	Tile Red;
	Tile Yellow;
	Tile Blue;
	Tile Green;
	Tile Alpha;
	Tile Magenta;



public:

	World();
	void loadFromFile(std::string &filename);
	void saveToFile(std::string &filename);
	void draw(sf::RenderWindow &window);

	void randomizeMapTiles();
	


};





#endif // !WORLD_H
