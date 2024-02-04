#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

class Game {
    public:
        Game();
        void run();

    private:
        sf::RenderWindow window;
        sf::Event event;

        sf::View view;
        float zoom = 5.f;
        bool zoomedOut = false;

        sf::Clock updateClock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        sf::Time targetUpdateTime = sf::seconds(1.f/60.f);

        sf::Texture tileset;
        sf::Font gameFont;

        void events();
        void update();
        void draw();
};