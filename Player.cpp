#include "Player.hpp"

void Player::initialize(sf::Texture* texture, sf::Vector2f position) {
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(size, 0, size, size));
    sprite.setPosition(position*static_cast<float>(size));
}

void Player::update() {
    if (movementCooldown > 0) {
        movementCooldown -= 1;
    } else {
        if (movementQueue.size() > 0) {
            sprite.move(movementQueue.front().x, movementQueue.front().y);
            lastMove = movementQueue.front();
            movementQueue.erase(movementQueue.begin());
            movementCooldown = speed;
        } else {
            lastMove = sf::Vector2f(0, 0);
        }
    }
    std::cout << movementQueue.size() << std::endl;
}

void Player::draw(sf::RenderWindow* window) {
    window->draw(sprite);
}

int Player::getRow() {
    return static_cast<int>(sprite.getPosition().y/size);
}

int Player::getColumn() {
    return static_cast<int>(sprite.getPosition().x/size);
}

void Player::setPosition(sf::Vector2f p) {
    sprite.setPosition(p);
}

void Player::queueMovement(sf::Vector2f offset) {
    if (movementQueue.empty() && offset != lastMove) {
        movementQueue.push_back(offset); 
    }
}