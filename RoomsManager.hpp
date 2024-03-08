#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.hpp"

class RoomsManager {
    public:
        RoomsManager() {};
        void initialize(sf::Texture* tilesetTexture);
        void update();
        void draw(sf::RenderWindow* window);

        bool canMoveUp(int currentRow, int currentColumn);
        bool canMoveLeft(int currentRow, int currentColumn);
        bool canMoveDown(int currentRow, int currentColumn);
        bool canMoveRight(int currentRow, int currentColumn);

    private:
        std::vector<std::vector<std::vector<Tile>>> rooms;

        int hideout = 0;
        int firstRoom = 1;
        int secondRoom = 2;
        int thirdRoom = 3;
        int fourthRoom = 4;
        int fifthRoom = 5;
        int sixthRoom = 6;

        int currentRoom = hideout;

        int hideoutRows = 25;
        int hideoutColumns = 25;

        int maximumRoomRows = 50;
        int maximumRoomColumns = 50;

        int maximumRoomCount = 6;

        void initializeHideout();
        void initializeRooms();

        sf::Texture* tileset;
        int tilesize = 20;
};