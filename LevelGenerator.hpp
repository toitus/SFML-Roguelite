#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Room.hpp"

class LevelGenerator {
    public:
        LevelGenerator();

        void initialize(sf::Font* font);

        void update();
        void draw();

    private:

        std::vector<Room> rooms;
        //loop through rooms here and call room functions for resizing randomly
        //randomize room connections here after resizing

        sf::Font* gameFont;

};