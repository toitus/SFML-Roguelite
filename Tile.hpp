#pragma once

#include <SFML/Graphics.hpp>

class Tile {

    public:
        Tile() {};

        void initialize(sf::Texture* tileset, int textureRow, int textureColumn, sf::Vector2f position, bool isWalkable) {
            sprite.setTexture(*tileset);
            sprite.setTextureRect(sf::IntRect(textureColumn*size, textureRow*size, size, size));
            sprite.setPosition(position);
            walkable = isWalkable;
        }

        void draw(sf::RenderWindow* window) {
            window->draw(sprite);
        }

    private:

        int size = 20;
        bool walkable;

        sf::Sprite sprite;

};