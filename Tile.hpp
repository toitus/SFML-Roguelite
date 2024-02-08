#pragma once

#include <SFML/Graphics.hpp>

class Tile {

    public:
        Tile() {};

        void initialize(sf::Texture* tileset, int textureRow, int textureColumn, sf::Vector2f position, bool isWalkable);

        void draw(sf::RenderWindow* window);

        void setTextureRect(int textureRow, int textureColumn);
        void setWalkable(bool w);

        bool isWalkable();

    private:

        int size = 20;
        bool walkable;

        sf::Sprite sprite;

};