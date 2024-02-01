#pragma once

#include "Room.hpp"

#include <vector>

class LevelGenerator {
    public:
        LevelGenerator();

        void update();
        void draw();

    private:

        std::vector<Room> rooms;
        //loop through rooms here and call room functions for resizing randomly
        //randomize room connections here after resizing

};