#include "Tile.hpp"

void Tile::initialize(sf::Texture* tileset, int textureRow, int textureColumn, sf::Vector2f position, bool isWalkable) {
    sprite.setTexture(*tileset);
    sprite.setTextureRect(sf::IntRect(textureColumn*size, textureRow*size, size, size));
    sprite.setPosition(position);
    walkable = isWalkable;
}

void Tile::draw(sf::RenderWindow* window) {
    window->draw(sprite);
}

void Tile::setTextureRect(sf::IntRect rect) {
    sprite.setTextureRect(rect);
}