#include "Hideout.hpp"

void Hideout::initialize(sf::Texture* tileset) {
    layout = std::vector<std::vector<Tile>>(rows, std::vector<Tile>(columns));
}

void Hideout::draw(sf::RenderWindow* window) {

}