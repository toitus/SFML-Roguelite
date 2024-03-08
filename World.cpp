#include "World.hpp"

void World::initialize(sf::Texture* tileset) {
    player.initialize(tileset, sf::Vector2f(12, 12));
    roomsManager.initialize(tileset);
}

void World::events(sf::Event* event) {
    if (event->type == sf::Event::KeyPressed) {
        // --- player movement ---
        if (event->key.code == sf::Keyboard::W && roomsManager.canMoveUp(player.getRow(), player.getColumn())) {
            player.queueMovement(up);
        }
        if (event->key.code == sf::Keyboard::A && roomsManager.canMoveLeft(player.getRow(), player.getColumn())) {
            player.queueMovement(left);
        }
        if (event->key.code == sf::Keyboard::S && roomsManager.canMoveDown(player.getRow(), player.getColumn())) {
            player.queueMovement(down);
        }
        if (event->key.code == sf::Keyboard::D && roomsManager.canMoveRight(player.getRow(), player.getColumn())) {
            player.queueMovement(right);
        }
        // --- end player movement ---
    }
}

void World::update() {
    player.update();
}

void World::draw(sf::RenderWindow* window) {
    player.draw(window);
    roomsManager.draw(window);
}

