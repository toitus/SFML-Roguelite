#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "Player.hpp"

class World {
    public:
        World() {};

        void initialize(sf::Texture* tileset);
        void update();
        void draw(sf::RenderWindow* window);

        sf::Vector2f getPlayerCenter();

    private:

        int tilesize = 20;

        std::vector<std::vector<std::vector<Tile>>> maps;

        int currentMap = 0;

        int hideoutRows = 25;
        int hideoutColumns = 25;

        Player player;

        void drawMaps(sf::RenderWindow* window);

        void handlePlayerMovement();

};