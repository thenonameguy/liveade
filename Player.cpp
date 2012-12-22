#include "Player.h"


void Player::reset()
{
    speed=2;
    texture.loadFromFile("img/player.png");
    sprite.setTexture(texture);
    pos=startPos;
    dead=false;
    points=0;
    bestPoint=0;
}

void Player::update()
{
    ++points;
    vel=sf::Vector2f();
    sf::Keyboard::isKeyPressed(sf::Keyboard::A)?  vel.x=-speed: (sf::Keyboard::isKeyPressed(sf::Keyboard::D))?
            vel.x=speed:
                  vel.x=0;
    sf::Keyboard::isKeyPressed(sf::Keyboard::W)?
    vel.y=-speed:
          (sf::Keyboard::isKeyPressed(sf::Keyboard::S))?
          vel.y=speed:
                vel.y=0;
    bool connected=sf::Joystick::isConnected(0);
    if(connected)
    {
        float xpos=sf::Joystick::getAxisPosition(0,sf::Joystick::X);
        float ypos=sf::Joystick::getAxisPosition(0,sf::Joystick::Y);
        vel.x=(xpos/50)*(xpos/50)*(xpos/50)*(MAXSPEED/2);
        vel.y=(ypos/50)*(ypos/50)*(ypos/50)*(MAXSPEED/2);
    }


    int length = sqrt(vel.x * vel.x + vel.y * vel.y);
    if(length>MAXSPEED)
    {
        vel.x=vel.x/length*MAXSPEED;
        vel.y=vel.y/length*MAXSPEED;
    }

    pos+=vel;
    if(pos.x>320)
    {
        pos.x=0-16;
        points+=300;
    }
    if(pos.x<0) pos.x=0;
    if(pos.y>320-8) pos.y=320-8;
    if(pos.y<0) pos.y=0;
    sprite.setPosition(pos);
}

void Player::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(sprite);
}

void Player::die()
{
    if(points>bestPoint)bestPoint=points;
    setPoints(0);
    dead=true;
    deadtime=0;
}

bool pointRect(float x, float y,const sf::RectangleShape& rect)
{
    float rw=rect.getSize().x;
    float rh=rect.getSize().y;
    float rx=rect.getPosition().x;
    float ry=rect.getPosition().y;
    return(x>rx&&x<rx+rw&&y>ry&&y<ry+rh);
}

bool Player::isColliding(const sf::FloatRect& other) const
{
    return sprite.getGlobalBounds().intersects(other);
}
