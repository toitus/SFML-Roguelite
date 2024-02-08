#include "Player.hpp"

void Player::initialize(sf::Texture* texture, sf::Vector2f position) {
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(size, 0, size, size));
    sprite.setPosition(position*(float)size);
}

void Player::update() {
    if (movementCooldown > 0) {
        movementCooldown -= 1;
    }
}

void Player::draw(sf::RenderWindow* window) {
    window->draw(sprite);
}

int Player::getRow() {
    return (int)sprite.getPosition().y/size;
}

int Player::getColumn() {
    return (int)sprite.getPosition().x/size;
}

void Player::moveUp() {
    if (movementCooldown == 0) {
        sprite.move(0, -size);
        movementCooldown = speed;
    }
}

void Player::moveLeft() {
    if (movementCooldown == 0) {
        sprite.move(-size, 0);
        movementCooldown = speed;
    }
}

void Player::moveDown() {
    if (movementCooldown == 0) {
        sprite.move(0, size);
        movementCooldown = speed;
    }
}

void Player::moveRight() {
    if (movementCooldown == 0) {
        sprite.move(size, 0);
        movementCooldown = speed;
    }
}