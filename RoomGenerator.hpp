#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.hpp"

class RoomGenerator {
    public:
        RoomGenerator() {};
        void initialize(sf::Texture* tileset);
        void update();
        void draw(sf::RenderWindow* window);

    private:
        std::vector<std::vector<std::vector<Tile>>> rooms;

        int currentMap = 0;

        int hideoutRows = 25;
        int hideoutColumns = 25;

        int maximumRoomRows = 50;
        int maximumRoomColumns = 50;

        int maximumRoomCount = 6;

        void initializeHideout();
        void initializeRooms();

        sf::Texture* tileset;
};