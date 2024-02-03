#pragma once

#include <SFML/Graphics.hpp>

class Hideout {
    public:
        Hideout();

        void initialize(sf::Font* font);

    private:

        sf::Font* gameFont;
    
};