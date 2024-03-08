#include "RoomsManager.hpp"

void RoomsManager::initialize(sf::Texture* tilesetTexture) {
    tileset = tilesetTexture;
    initializeHideout();
    initializeRooms();
}

void RoomsManager::update() {

}

void RoomsManager::draw(sf::RenderWindow* window) {
    for (int r = 0; r < rooms[currentRoom].size(); ++r) {
        for (int c = 0; c < rooms[currentRoom][r].size(); ++c) {
            rooms[currentRoom][r][c].draw(window);
        }
    }
}

void RoomsManager::initializeHideout() {
    //push 2d vector for hideout
    rooms.push_back(std::vector<std::vector<Tile>>(hideoutRows, std::vector<Tile>(hideoutColumns)));

    //initializing tiles for hideout
    for (int r = 0; r < hideoutRows; ++r) {
        for (int c = 0; c < hideoutColumns; ++c) {
            rooms[hideout][r][c].initialize(tileset, 0, 0, sf::Vector2f(c*tilesize, r*tilesize), false);
        }
    }

    //constructing hideout {
    //all tiles that are not on the border
    for (int r = 1; r < (hideoutRows-1); ++r) {
        for (int c = 1; c < (hideoutColumns-1); ++c) {
            rooms[hideout][r][c].setTextureRect(0, 0);
            rooms[hideout][r][c].setWalkable(true);
        }
    }
    //all border tiles that are not corners
    //left and right border
    for (int r = 1; r < (hideoutRows-1); ++r) {
        rooms[hideout][r][0].setTextureRect(11, 10);
        rooms[hideout][r][hideoutColumns-1].setTextureRect(11, 10);
    }
    //top and bottom border
    for (int c = 1; c < (hideoutColumns-1); ++c) {
        rooms[hideout][0][c].setTextureRect(12, 13);
        rooms[hideout][hideoutRows-1][c].setTextureRect(12, 13);
    }
    //corners
    rooms[hideout][0][0].setTextureRect(12, 9);
    rooms[hideout][0][hideoutColumns-1].setTextureRect(11, 11);
    rooms[hideout][hideoutRows-1][0].setTextureRect(12, 8);
    rooms[hideout][hideoutRows-1][hideoutColumns-1].setTextureRect(11, 12);
    //}
}

void RoomsManager::initializeRooms() {
    for (int i = 0; i < maximumRoomCount; ++i) {
        rooms.push_back(std::vector<std::vector<Tile>>(maximumRoomRows, std::vector<Tile>(maximumRoomColumns)));
    }
}

bool RoomsManager::canMoveUp(int currentRow, int currentColumn) {
    return rooms[currentRoom][currentRow-1][currentColumn].isWalkable();
}

bool RoomsManager::canMoveLeft(int currentRow, int currentColumn) {
    return rooms[currentRoom][currentRow][currentColumn-1].isWalkable();
}

bool RoomsManager::canMoveDown(int currentRow, int currentColumn) {
    return rooms[currentRoom][currentRow+1][currentColumn].isWalkable();
}

bool RoomsManager::canMoveRight(int currentRow, int currentColumn) {
    return rooms[currentRoom][currentRow][currentColumn+1].isWalkable();
}