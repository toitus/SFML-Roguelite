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

void Tile::setTextureRect(int textureRow, int textureColumn) {
    sprite.setTextureRect(sf::IntRect(textureColumn*size, textureRow*size, size, size));
}

void Tile::setWalkable(bool w) {
    walkable = w;
}

bool Tile::isWalkable() {
    return walkable;
}