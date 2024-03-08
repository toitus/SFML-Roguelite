#include "World.hpp"

void World::initialize(sf::Texture* tileset) {
    constructHideout(tileset);
    initializeRoomVectors();
    player.initialize(tileset, sf::Vector2f(static_cast<int>(hideoutColumns/2), static_cast<int>(hideoutRows/2)));
}

void World::events(sf::Event* event) {
    if (event->type == sf::Event::KeyPressed) {
        // --- player movement ---
        if (event->key.code == sf::Keyboard::W && rooms[currentMap][player.getRow()-1][player.getColumn()].isWalkable()) {
            player.queueMovement(up);
        }
        if (event->key.code == sf::Keyboard::A && rooms[currentMap][player.getRow()][player.getColumn()-1].isWalkable()) {
            player.queueMovement(left);
        }
        if (event->key.code == sf::Keyboard::S && rooms[currentMap][player.getRow()+1][player.getColumn()].isWalkable()) {
            player.queueMovement(down);
        }
        if (event->key.code == sf::Keyboard::D && rooms[currentMap][player.getRow()][player.getColumn()+1].isWalkable()) {
            player.queueMovement(right);
        }
        // --- end player movement ---
    }
}

void World::update() {
    player.update();
}

void World::draw(sf::RenderWindow* window) {
    drawMap(window);
    player.draw(window);
}

void World::drawMap(sf::RenderWindow* window) {
    for (int r = 0; r < rooms[currentMap].size(); ++r) {
        for (int c = 0; c < rooms[currentMap][r].size(); ++c) {
            rooms[currentMap][r][c].draw(window);
        }
    }
}

void World::constructHideout(sf::Texture* tileset) {
    //push 2d vector for hideout
    rooms.push_back(std::vector<std::vector<Tile>>(hideoutRows, std::vector<Tile>(hideoutColumns)));

    //initializing tiles for hideout
    for (int r = 0; r < hideoutRows; ++r) {
        for (int c = 0; c < hideoutColumns; ++c) {
            rooms[0][r][c].initialize(tileset, 0, 0, sf::Vector2f(c*tilesize, r*tilesize), false);
        }
    }

    //constructing hideout {
    //all tiles that are not on the border
    for (int r = 1; r < (hideoutRows-1); ++r) {
        for (int c = 1; c < (hideoutColumns-1); ++c) {
            rooms[0][r][c].setTextureRect(0, 0);
            rooms[0][r][c].setWalkable(true);
        }
    }
    //all border tiles that are not corners
    //left and right border
    for (int r = 1; r < (hideoutRows-1); ++r) {
        rooms[0][r][0].setTextureRect(11, 10);
        rooms[0][r][hideoutColumns-1].setTextureRect(11, 10);
    }
    //top and bottom border
    for (int c = 1; c < (hideoutColumns-1); ++c) {
        rooms[0][0][c].setTextureRect(12, 13);
        rooms[0][hideoutRows-1][c].setTextureRect(12, 13);
    }
    //corners
    rooms[0][0][0].setTextureRect(12, 9);
    rooms[0][0][hideoutColumns-1].setTextureRect(11, 11);
    rooms[0][hideoutRows-1][0].setTextureRect(12, 8);
    rooms[0][hideoutRows-1][hideoutColumns-1].setTextureRect(11, 12);
    //}
}

void World::initializeRoomVectors() {
    for (int i = 0; i < maximumRoomCount; ++i) {
        rooms.push_back(std::vector<std::vector<Tile>>(maximumRoomRows, std::vector<Tile>(maximumRoomColumns)));
    }
}

