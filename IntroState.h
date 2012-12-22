#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

#include <algorithm>
#include <vector>

#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameEngine;

class IntroState : public GameState
{
public:
    IntroState( GameEngine& game, bool replace = true );

    void pause();
    void resume();

    void update();
    void draw();

private:
    int pwidth;
    int pheight;
    std::vector<sf::Uint8> pixels;
    sf::Text liveade;
    sf::Text pressEnter;
    sf::Texture bg;
    sf::Sprite sprite;
};

#endif // INTROSTATE_HPP
