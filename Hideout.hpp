#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.hpp"

class Hideout {
    public:
        Hideout() {};

        void initialize(sf::Texture* tileset);

        void draw(sf::RenderWindow* window);

    private:

        int rows = 30;
        int columns = 30;

        std::vector<std::vector<Tile>> layout;

};