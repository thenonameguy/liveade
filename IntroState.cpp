// *** ADDED BY HEADER FIXUP ***
#include <cstdlib>
// *** END ***
#include <memory>
#include <iostream>

#include "IntroState.h"
#include "PlayState.h"
#include "GameEngine.h"

IntroState::IntroState( GameEngine& game, bool replace ) : GameState( game, replace )
{
    pwidth=game.screen.getSize().x;
    pheight=game.screen.getSize().y;
    bg.create(pwidth,pheight);
    sprite.setTexture(bg);
    pixels.reserve(pwidth*pheight*4);
    liveade.setFont(game.font);
    liveade.setCharacterSize(30);
    liveade.setStyle(sf::Text::Bold);
    liveade.setString("Liveade");
    liveade.setPosition(10,10);
    pressEnter.setFont(game.font);
    pressEnter.setCharacterSize(30);
    pressEnter.setString("Press Enter");
    pressEnter.setPosition(10,280);
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
    bool connected=sf::Joystick::isConnected(0);
    if(connected)
    {
        unsigned int buttonCount=sf::Joystick::getButtonCount(0);
        for (int i = 0; i < buttonCount; ++i)
        {
            std::cout<<"Button "<<i<<" :"<<sf::Joystick::isButtonPressed(0,i)<<std::endl;
        }
        float xpos=sf::Joystick::getAxisPosition(0,sf::Joystick::X);
        float ypos=sf::Joystick::getAxisPosition(0,sf::Joystick::Y);
        std::cout<<"X: "<<xpos<<" Y: "<<ypos<<" ;"<<std::endl;
    }

    int pixelCount=pwidth*pheight*4;
    sf::Uint8 foo=0;
    for (int i = 0; i < pixelCount ; ++i)
    {
        if(i%4==0)foo=rand()%140;
        pixels[i]=foo;
    }
    bg.update(&pixels[0]);
}

void IntroState::draw()
{
    m_game.screen.clear();
    m_game.screen.draw(sprite);
    m_game.screen.draw(liveade);
    m_game.screen.draw(pressEnter);
    m_game.screen.display();
}

