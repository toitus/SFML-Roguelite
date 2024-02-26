#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "Player.hpp"

class World {
    public:
        World() {};

        void initialize(sf::Texture* tileset);
        void events(sf::Event* event);
        void update();
        void draw(sf::RenderWindow* window);

    private:

        int tilesize = 20;

        std::vector<std::vector<std::vector<Tile>>> maps;

        int currentMap = 0;

        int hideoutRows = 25;
        int hideoutColumns = 25;

        Player player;
        sf::Vector2f up = sf::Vector2f(0, -20);
        sf::Vector2f left = sf::Vector2f(-20, 0);
        sf::Vector2f down = sf::Vector2f(0, 20);
        sf::Vector2f right = sf::Vector2f(20, 0);

        sf::Keyboard::Key lastKeyPressed = sf::Keyboard::Unknown;

        void drawMap(sf::RenderWindow* window);

        void handlePlayerMovement();

        void constructHideout(sf::Texture* tileset);

        //pathfinding for enemy to player
        //take difference of row/column of enemy and player
        //advance toward adjacent square randomly choosing open tiles

};