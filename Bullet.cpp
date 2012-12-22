#include "Bullet.h"

void Bullet::update()
{
    pos+=vec;
    shape.setPosition(pos);
    if(pos.x+width<0)
    {
        moveToSafe();
    }
}

void Bullet::moveToSafe()
{
    pos.x=320+rand()%320;
    pos.y=rand()%320+1;
}

void Bullet::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(shape);
}
