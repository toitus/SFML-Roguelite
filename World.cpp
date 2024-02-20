#include "World.hpp"

void World::initialize(sf::Texture* tileset) {
    constructHideout(tileset);
    player.initialize(tileset, sf::Vector2f((int)hideoutColumns/2, (int)hideoutRows/2));
}

void World::events(sf::Event* event) {
    if (event->type == sf::Event::KeyPressed) {
        lastKeyPressed = event->key.code;
    }
}

void World::update() {
    player.update();
    handlePlayerMovement();
}

void World::draw(sf::RenderWindow* window) {
    drawMap(window);
    player.draw(window);
}

void World::drawMap(sf::RenderWindow* window) {
    for (int r = 0; r < maps[currentMap].size(); ++r) {
        for (int c = 0; c < maps[currentMap][r].size(); ++c) {
            maps[currentMap][r][c].draw(window);
        }
    }
}

void World::handlePlayerMovement() {
    bool w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool a = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    bool d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

    bool last = sf::Keyboard::isKeyPressed(lastKeyPressed);

    if (w && (lastKeyPressed == sf::Keyboard::W || !last) && maps[currentMap][player.getRow()-1][player.getColumn()].isWalkable()) {
        player.moveUp(); //queue here instead?!
    }

    if (a && (lastKeyPressed == sf::Keyboard::A || !last) && maps[currentMap][player.getRow()][player.getColumn()-1].isWalkable()) {
        player.moveLeft();
    }

    if (s && (lastKeyPressed == sf::Keyboard::S || !last) && maps[currentMap][player.getRow()+1][player.getColumn()].isWalkable()) {
        player.moveDown();
    }

    if (d && (lastKeyPressed == sf::Keyboard::D || !last) && maps[currentMap][player.getRow()][player.getColumn()+1].isWalkable()) {
        player.moveRight();
    }
}

void World::constructHideout(sf::Texture* tileset) {
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
}

