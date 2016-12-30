#include "Game.h"
#include <iostream>
//private:
//sf::RenderWindow mWindow;


Game::Game() {
	activeMode = editorMode;
	mWindow.create(sf::VideoMode(WIDTH, HEIGHT), "RPG Maker",sf::Style::Close);
	mWindow.setActive(true);
	mWindow.setFramerateLimit(60);
}
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
	switch (key) {
	case sf::Keyboard::L:
		world.loadFromFile(std::string("tiles.txt"));
		break;
	case sf::Keyboard::S:
		world.saveToFile(std::string("tiles.txt"));
		break;
	case sf::Keyboard::R:
		world.randomizeMapTiles();
		break;
	case sf::Keyboard::T:
		toggleMode();
		break;
	}
}
void Game::toggleMode(){
	if (activeMode == Normal) activeMode = editorMode;
	else activeMode = Normal;
}
void Game::processEvents() {
	sf::Event mEvent;

	while (mWindow.pollEvent(mEvent)) {

		switch (mEvent.type) {

		case sf::Keyboard::Escape:
					mWindow.close();
					break;
		
		case sf::Event::Closed:
					mWindow.close();
					break;

		case sf::Event::KeyPressed:
					handlePlayerInput(mEvent.key.code, true);
					break;

		case sf::Event::KeyReleased:
					handlePlayerInput(mEvent.key.code, false);
					break;
		}//!switch
	}//!while

}

void Game::render() {
	mWindow.clear(sf::Color::White);

	world.draw(mWindow);
	
	if(activeMode == editorMode)	editor.render(mWindow);



	mWindow.display();
}

void Game::run() {

	while (mWindow.isOpen()) {

		switch (activeMode) {
		case editorMode:
			processEvents();
			update();
			render();
			break;

		case Normal:
			processEvents();
			update();
			render();
		}
		
	


	}
}

void Game::update() {
	if(activeMode == editorMode)	editor.update(mWindow);


}