//Author: Kacper Olek



//SFML Headers
#include "SFML\System.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"


//Game Headers
#include "Game.h"
#include "Monster.h"
#include "World.h"
#include "Player.h"



int main(void) {
	Game game;

	game.run();



	return EXIT_SUCCESS;
}