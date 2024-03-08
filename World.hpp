#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "Player.hpp"
#include "RoomsManager.hpp"

class World {
    public:
        World() {};

        void initialize(sf::Texture* tileset);
        void events(sf::Event* event);
        void update();
        void draw(sf::RenderWindow* window);

    private:

        Player player;
        sf::Vector2f up = sf::Vector2f(0, -20);
        sf::Vector2f left = sf::Vector2f(-20, 0);
        sf::Vector2f down = sf::Vector2f(0, 20);
        sf::Vector2f right = sf::Vector2f(20, 0);

        void handlePlayerMovement();

        RoomsManager roomsManager;

        //pathfinding for enemy to player
        //take difference of row/column of enemy and player
        //advance toward adjacent square randomly choosing open tiles

};