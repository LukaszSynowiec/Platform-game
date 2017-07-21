#include "Bullet.h"
#include <iostream>


Bullet::Bullet()
{
	body.setRadius(3);
	body.setFillColor(sf::Color::Black);
	speed = 3;
	
}


Bullet::~Bullet()
{
}
void Bullet::shot()
{
	canDraw = true;

}
void Bullet::setPosition(sf::Vector2f pos)
{
	body.setPosition(pos);
}
bool Bullet::draw(sf::RenderWindow &window,bool faceRight, Player &playerCharacter)
{
	sf::Vector2f movement;
	if (canDraw)
	{
		if (oneCheck == false)
		{
			(faceRight) ? Dir=RIGHT : Dir=LEFT;
			oneCheck = true;
		}
		switch (Dir)
		{
		case LEFT:
		{
			movement.x -= speed;
		}
		break;
		case RIGHT:
		{
			movement.x += speed;
		}
		break;
		}
		body.move(movement);
		window.draw(body);
		if (body.getGlobalBounds().intersects(playerCharacter.getSprite().getGlobalBounds()))
		{
			return true;
		}
		else
			return false;
	}
}



