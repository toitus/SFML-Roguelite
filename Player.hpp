#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player {
    public:
        Player() {};

        void initialize(sf::Texture* texture, sf::Vector2f position);

        void update();
        void draw(sf::RenderWindow* window);

        int getRow();
        int getColumn();

        void setPosition(sf::Vector2f p);

        void moveUp();
        void moveLeft();
        void moveDown();
        void moveRight();

        void queueMovement(sf::Vector2f offset);

    private:
        sf::Sprite sprite;

        int size = 20;

        //update at 60fps, 30 frames = 0.5 seconds
        int movementCooldown = 0;
        int speed = 24;

        std::vector<sf::Vector2f> movementQueue;
        sf::Vector2f lastMove = sf::Vector2f(0, 0);

};