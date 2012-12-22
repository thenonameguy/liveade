#ifndef HG_PLAYER
#define HG_PLAYER
#include <cmath>
#include <string>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Player: public sf::Drawable
{
public:
    Player():startPos(155,155)
    {
        reset();
    }
    Player(const sf::Vector2f& start):startPos(start)
    {
        reset();
    }
    Player(float x, float y):startPos(x,y)
    {
        reset();
    }
    void update();
    std::string getPoints() const
    {
        std::stringstream ss(std::stringstream::in|std::stringstream::out);
        ss<<points;
        return ss.str();
    }
    std::string getBestPoint() const
    {
        std::stringstream ss(std::stringstream::in|std::stringstream::out);
        ss<<points;
        return ss.str();
    }
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    bool isColliding(const sf::FloatRect&) const;
    void changePoints(int change)
    {
        if(points+change<0)points=0;
        else points+=change;
    }
    void die();
private:
    void afterDeath()
    {
        dead=false;
        deadtime=0;
    }
    static const int MAXSPEED=2;
    void setPoints(unsigned int x=0)
    {
        points=x;
    }
    void reset();
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f startPos;
    sf::Vector2f pos;
    sf::Vector2f acc;
    sf::Vector2f vel;
    unsigned int points;
    unsigned int bestPoint;
    sf::Color color;
    int deadtime;
    bool dead;
    int speed;
};
#endif
