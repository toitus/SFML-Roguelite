#include "World.hpp"

void World::initialize(sf::Texture* tileset) {
    //push 2d vector for hideout
    maps.push_back(std::vector<std::vector<Tile>>(hideoutRows, std::vector<Tile>(hideoutColumns)));

    //initializing tiles for hideout
    for (int r = 0; r < hideoutRows; ++r) {
        for (int c = 0; c < hideoutColumns; ++c) {
            maps[0][r][c].initialize(tileset, 0, 0, sf::Vector2f(c*tilesize, r*tilesize), false);
        }
    }

    //constructing hideout {
    //all tiles that are not on the border
    for (int r = 1; r < (hideoutRows-1); ++r) {
        for (int c = 1; c < (hideoutColumns-1); ++c) {
            maps[0][r][c].setTextureRect(0, 0);
            maps[0][r][c].setWalkable(true);
        }
    }
    //all border tiles that are not corners
    //left and right border
    for (int r = 1; r < (hideoutRows-1); ++r) {
        maps[0][r][0].setTextureRect(11, 10);
        maps[0][r][hideoutColumns-1].setTextureRect(11, 10);
    }
    //top and bottom border
    for (int c = 1; c < (hideoutColumns-1); ++c) {
        maps[0][0][c].setTextureRect(12, 13);
        maps[0][hideoutRows-1][c].setTextureRect(12, 13);
    }
    //corners
    maps[0][0][0].setTextureRect(12, 9);
    maps[0][0][hideoutColumns-1].setTextureRect(11, 11);
    maps[0][hideoutRows-1][0].setTextureRect(12, 8);
    maps[0][hideoutRows-1][hideoutColumns-1].setTextureRect(11, 12);
    //}

    player.initialize(tileset, sf::Vector2f((int)hideoutColumns/2, (int)hideoutRows/2));
    
}

void World::update() {
    player.update();
    handlePlayerMovement();
}

void World::draw(sf::RenderWindow* window) {
    drawMaps(window);
    player.draw(window);
}

void World::drawMaps(sf::RenderWindow* window) {
    for (int m = 0; m < maps.size(); ++m) {
        for (int r = 0; r < maps[m].size(); ++r) {
            for (int c = 0; c < maps[m][r].size(); ++c) {
                maps[m][r][c].draw(window);
            }
        }
    }
}

void World::handlePlayerMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && maps[currentMap][player.getRow()-1][player.getColumn()].isWalkable()) {
        player.moveUp();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && maps[currentMap][player.getRow()][player.getColumn()-1].isWalkable()) {
        player.moveLeft();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && maps[currentMap][player.getRow()+1][player.getColumn()].isWalkable()) {
        player.moveDown();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && maps[currentMap][player.getRow()][player.getColumn()+1].isWalkable()) {
        player.moveRight();
    }
}

sf::Vector2f World::getPlayerCenter() {
    return sf::Vector2f((player.getColumn()*tilesize)+10, (player.getRow()*tilesize)+10);
}