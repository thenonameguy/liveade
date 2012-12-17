#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

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
	sf::Texture m_bgTex;
	sf::Sprite m_bg;
};

#endif // INTROSTATE_HPP
