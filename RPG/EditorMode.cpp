#include "EditorMode.h"

EditorMode::EditorMode(){
	highlight = Tile(sf::Color::Transparent, sf::Vector2f(WIDTH / SIZE, HEIGHT / SIZE));
	highlight.setOutlineColor(sf::Color::Red);
	highlight.setOutlineThickness(6);
	highlightedTile = sf::Vector2i(0, 0);
	highlight.setOrigin(sf::Vector2f(2, 1));
}


void EditorMode::update(sf::RenderWindow &window) {
	
		sf::Vector2i pos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

		for (int i = 0; i < SIZE; i++) {
			if (pos.x > i*(WIDTH / SIZE) && pos.x < (i + 1)*(WIDTH / SIZE)) {
				highlight.setPosition(sf::Vector2f(i*(WIDTH / SIZE), highlight.getPosition().y));
				highlightedTile.x = i;
				break;
			}
		}
		for (int i = 0; i < 18; i++) {
			if (pos.y > i*(HEIGHT / SIZE) && pos.y <(i + 1)*(HEIGHT / SIZE)) {
				highlight.setPosition(sf::Vector2f(highlight.getPosition().x, i*(HEIGHT / SIZE)));
				highlightedTile.y = i;

				break;

			}
		}

}
void EditorMode::render(sf::RenderWindow &window){
	highlight.draw(window);
}
