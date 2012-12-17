#include <memory>
#include <iostream>

#include "IntroState.h"
#include "PlayState.h"
#include "GameEngine.h"

IntroState::IntroState( GameEngine& game, bool replace ) : GameState( game, replace )
{

}

void IntroState::pause()
{
}

void IntroState::resume()
{
}

void IntroState::update()
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
            {
                switch( event.key.code )
                {
					case sf::Keyboard::Return:
                        m_next = m_game.activate<PlayState>(true);
                        break;
					case sf::Keyboard::P:
                        m_next = m_game.activate<PlayState>(false);
						break;

                    case sf::Keyboard::Escape:
                        m_game.quit();
                        break;
                }
                break;
            }
		}
	}
}

void IntroState::draw()
{
	m_game.screen.clear();

	m_game.screen.display();
}

