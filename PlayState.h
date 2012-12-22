#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Player.h"
#include "Bullet.h"

class GameEngine;

class PlayState : public GameState
{
public:
	PlayState( GameEngine& game, bool replace = true );

	void pause();
	void resume();

	void update();
	void draw();

	void saveHighscore();

private:
	const int MAXBULLET=100;
	Player p;
	Player p2;
	sf::Color clearColor;
	sf::Font bitFont;
	sf::Text points;
	sf::Text highscore;
	std::vector<Bullet> bullets;
	sf::Clock clock;
	sf::Event event;
	int usedBullets;
};

#endif 
