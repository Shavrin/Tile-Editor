#ifndef GAME_H
#define GAME_H

#define SIZE 20

#define WIDTH 640.f
#define HEIGHT 480.f

#include "SFML\Graphics.hpp"
#include "World.h"
#include "EditorMode.h"

enum _gameMode {
	editorMode,Normal
};



class Game {

public:

		 Game();
	void run();
	
private:
	void	render();
	void	update();
	void	processEvents();

	void	handlePlayerInput(sf::Keyboard::Key key,bool isPressed);
	void	toggleMode();
private:
	sf::RenderWindow	mWindow;
	World				world;
	_gameMode activeMode;
	EditorMode editor;
public:



};


#endif // !GAME_H