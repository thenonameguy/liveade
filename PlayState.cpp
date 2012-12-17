#include <memory>
#include <iostream>

#include "PlayState.h"
#include "IntroState.h"
#include "GameEngine.h"

PlayState::PlayState( GameEngine& game, bool replace ) : GameState( game, replace )
{
	points.setFont(game.font);
	highscore.setFont(game.font);
	points.setCharacterSize(10);
	highscore.setCharacterSize(10);
	points.setString("Points: 0");
	highscore.setString("Best: 0");
	highscore.setPosition(0,15);

	for (int i = 0; i < MAXBULLET; ++i) 
	{
		bullets.push_back(*(new Bullet()));
		bullets[i].moveToSafe();
	}
	usedBullets=30;
}

void PlayState::pause()
{
	std::cout << "Paused" << std::endl;
}

void PlayState::resume()
{
	std::cout << "Resumed" << std::endl;
}

void PlayState::update()
{
	sf::Event event;

	while( m_game.screen.pollEvent( event ) )
	{
		switch( event.type )
		{
			case sf::Event::Closed:
				m_game.quit();
				break;

			case sf::Event::KeyPressed:
				switch( event.key.code )
				{
					case sf::Keyboard::Escape:
						m_game.quit();
						break;
					case sf::Keyboard::P:
						//TODO: Replace with PauseState
						m_next=m_game.activate<IntroState>(false);

						break;
				}
				break;
		}
	}
	points.setString("Points: "+p.getPoints());
	highscore.setString("Best: "+p.getBestPoint());
	p.update();
	if(clock.getElapsedTime().asMilliseconds()%100==0 && usedBullets<MAXBULLET)
	{
		bullets[usedBullets].moveToSafe();
		++usedBullets;
	}

	for (int i = 0; i < usedBullets; ++i) 
	{
		bullets[i].update();
		if(p.isColliding(bullets[i].shape.getGlobalBounds()))
		{
			p.die();
			bullets[i].moveToSafe();
		}
	}
}

void PlayState::draw()
{
	m_game.screen.clear(sf::Color(30,30,30));
	for (int i = 0; i < usedBullets; ++i) 
		m_game.screen.draw(bullets[i]);
	m_game.screen.draw(p);
	m_game.screen.draw(points);
	m_game.screen.draw(highscore);
	m_game.screen.display();
}

void PlayState::saveHighscore()
{
	std::cout<<"Your highscore is "<<p.getBestPoint()<<" points, great job!"<<std::endl;
	std::cout<<"Name: ";
	std::string name;
	std::cin>>name;
	std::ofstream highscores("highscores.dat",std::ios::app);
	if(highscores.is_open())
	{
		highscores<<name<<" "<<p.getBestPoint()<<std::endl;
		highscores.close();
	}
}

