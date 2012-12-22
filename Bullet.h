#ifndef HG_BULLET
#define HG_BULLET

#include <cstdlib>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

class Bullet : public sf::Drawable
{
public:
    Bullet():shape(sf::Vector2f(width,1)),vec(sf::Vector2f(-(rand()%4+1),0))
    {
        pos=sf::Vector2f(rand()%320+1,rand()%320+1);
        color=sf::Color(rand()%255,rand()%128+128,rand()%128+128);
        shape.setFillColor(color);
    }

    void moveToSafe();
    void update();
    sf::RectangleShape shape;
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
private:
    sf::Color color;
    sf::Vector2f pos;
    sf::Vector2f vec;
    static const int width=10;
};
#endif
