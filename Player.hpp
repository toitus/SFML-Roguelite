#pragma once

#include <SFML/Graphics.hpp>

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

    private:
        sf::Sprite sprite;

        int size = 20;

        //update at 60fps, 30 frames = 0.5 seconds
        int movementCooldown = 0;
        int speed = 24;


};