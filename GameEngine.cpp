#include "GameEngine.h"

#include <memory>
#include <iostream>
#include "GameState.h"

#include "IntroState.h"
#include "GameState.h"

GameEngine::GameEngine( const std::string& title, const unsigned int width, const unsigned int height, const unsigned int bpp, const bool fullscreen ) :
    m_resume( false ),
	m_running( false ),
	m_fullscreen( fullscreen )
{
	int flags = 0;

	if( fullscreen )
		flags = sf::Style::Fullscreen;
	else
		flags = sf::Style::Default;

	font.loadFromFile("8bit.ttf");
	screen.create( sf::VideoMode( width, height, bpp ), title, flags );
	screen.setFramerateLimit( 60 );
}

void GameEngine::run( std::unique_ptr<GameState> state )
{
	m_running = true;

	m_states.push( std::move( state ) );
}

void GameEngine::nextState()
{
    if(m_resume)
    {
        if ( !m_states.empty() ) m_states.pop();
        if ( !m_states.empty() ) m_states.top()->resume();
        m_resume = false;
    }

	if ( !m_states.empty() )
	{
		std::unique_ptr<GameState> temp = m_states.top()->next();
		if( temp != nullptr )
		{
			temp->isReplacing()?m_states.pop():	m_states.top()->pause();
			m_states.push( std::move( temp ) );
		}
	}
}

void GameEngine::lastState(){m_resume = true;}
void GameEngine::update(){	m_states.top()->update();}
void GameEngine::draw(){m_states.top()->draw();}
