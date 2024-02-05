#include "Hideout.hpp"

void Hideout::initialize(sf::Texture* tileset) {
    layout = std::vector<std::vector<Tile>>(rows, std::vector<Tile>(columns));

    //all tiles that are not on the border
    for (int r = 1; r < rows-1; ++r) {
        for (int c = 1; c < columns-1; ++c) {
            layout[r][c].initialize(tileset, 2, 11, sf::Vector2f(c*tilesize, r*tilesize), true);
        }
    }

    //all border tiles that are not corners
    //left and right border
    for (int r = 1; r < rows-1; ++r) {
        layout[r][0].initialize(tileset, 11, 10, sf::Vector2f(0, r*tilesize), false);
        layout[r][columns-1].initialize(tileset, 11, 10, sf::Vector2f((columns-1)*tilesize, r*tilesize), false);
    }

    //top and bottom border
    for (int c = 1; c < columns-1; ++c) {
        layout[0][c].initialize(tileset, 12, 13, sf::Vector2f(c*tilesize, 0), false);
        layout[rows-1][c].initialize(tileset, 12, 13, sf::Vector2f(c*tilesize, (rows-1)*tilesize), false);
    }

    //corners
    layout[0][0].initialize(tileset, 12, 9, sf::Vector2f(0, 0), false);
    layout[0][columns-1].initialize(tileset, 11, 11, sf::Vector2f((columns-1)*tilesize, 0), false);
    layout[rows-1][0].initialize(tileset, 12, 8, sf::Vector2f(0, (rows-1)*tilesize), false);
    layout[rows-1][columns-1].initialize(tileset, 11, 12, sf::Vector2f((columns-1)*tilesize, (rows-1)*tilesize), false);

}

void Hideout::draw(sf::RenderWindow* window) {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            layout[r][c].draw(window);
        }
    }
}