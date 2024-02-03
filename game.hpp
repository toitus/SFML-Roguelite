#pragma once

#include <SFML/Graphics.hpp>

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

        sf::Font gameFont;

        void events();
        void update();
        void draw();
};