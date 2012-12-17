#include "Player.h"


void Player::reset()
{
	speed=2;
	texture.loadFromFile("img/player.png");
	texture.setSmooth(false);
	sprite.setTexture(texture);
	pos=startPos;
	dead=false;
	points=0;
	bestPoint=0;
}

void Player::update()
{
/*	if(dead && deadtime<10)
	{
		++deadtime;
		return;
	}
	else
	{
		afterDeath();
	}
*/
	++points;
	vel=sf::Vector2f();
	sf::Keyboard::isKeyPressed(sf::Keyboard::A)?
		vel.x=-speed:
		(sf::Keyboard::isKeyPressed(sf::Keyboard::D))?
			vel.x=speed:
			vel.x=0;
	sf::Keyboard::isKeyPressed(sf::Keyboard::W)?
		vel.y=-speed:
		(sf::Keyboard::isKeyPressed(sf::Keyboard::S))?
			vel.y=speed:
			vel.y=0;

	int length = sqrt(vel.x * vel.x + vel.y * vel.y);
	if(length>MAXSPEED)
	{
		vel.x=vel.x/length*MAXSPEED;
		vel.y=vel.y/length*MAXSPEED;
	}

	pos+=vel;
	if(pos.x>320){ pos.x=0-16;points+=300;}
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
