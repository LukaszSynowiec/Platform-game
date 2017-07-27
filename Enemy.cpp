#include "Enemy.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"
#include <cstdlib>
#include "Bullet.h"

Enemy::Enemy(std::string file, float speed, int health, sf::Vector2f position)
	:animation( { 4,1}, 0.1f)

{
	this->speed = speed;
	texture.loadFromFile("data/" + file);
	body.setTexture(texture);
	body.setPosition(position);
	this->health = health;
	erase.setPosition({ -100,-100 });
	STATE = Patrolling;
	animation.uvRect.width = 32;
	animation.uvRect.height = 65;
	for (int i = 0; i < 10; i++)
	{
		bullet[i].setPosition({ -100, -100 });
	}
	ammo = 9;

}
Enemy::~Enemy()
{
}
void Enemy::setState(int TEMP)
{
	STATE = static_cast<State>(TEMP);
}
int Enemy::getState()
{
	return static_cast<int>(STATE);
}

void Enemy::Update(float deltaTime,sf::FloatRect boundingBox,sf::Vector2f playerPosition,Player &player,sf::RenderWindow &window)
{
	sf::Vector2f movement(0,0);
	if (STATE == Patrolling)
	{
		temp = 1;
		if (isGoingLeft)
		{
			if (body.getPosition().x <= 870)
			{
		
				isGoingLeft = false;
				isGoingRight = true;
			}
			else
			{
				faceRight = false;
				movement.x -= speed*deltaTime;
			}

		}
		if (isGoingRight)
		{
			if (body.getPosition().x >= 1020)
			{
		
				isGoingLeft = true;
				isGoingRight = false;
			}
			else
			{
				faceRight = true;
				movement.x += speed*deltaTime;
			}

		}
	}
	body.move(movement);
	position = body.getPosition();
	bodyBoundingBox = body.getGlobalBounds();
	//pozycja y -60
	if (playerPosition.y <= 80 && player.State == static_cast <Player::STATE>(1) && calculateDistance(playerPosition) <= 600&&ammo>0)
	{
				canShot = true;
				STATE = Shoots;
	}
	else
	{
		STATE = Patrolling;
	}
	if (bodyBoundingBox.intersects(boundingBox))
	{
		//kolizja
	}
	if (STATE == Shoots)
	{
		
		 (calculateDistance(playerPosition) > 0) ? faceRight = false : faceRight = true;
		 if(temp==1)
		 {
			 row = 2;
			 animation.currentImage.x = 5;
			 animation.Update(row, deltaTime, faceRight);
			 body.setTextureRect(animation.uvRect);
			 temp = 0;
		 }
		 else
		 {
			 row = 0;
		 }
		 if (canShot)
		 {
			 if (faceRight == true)
			 {
				 row = 2;
				 animation.currentImage.x = 4;
				 animation.Update(row, deltaTime, faceRight);
				 body.setTextureRect(animation.uvRect);
				}  
			 if (timeBetweenShots <= 0)
			 {
				 if (ammo > 0)
				 {
					 sf::Vector2f x;
					 x = position;
					 x.y += 32;
					 bullet[ammo].setPosition(x);
					 bullet[ammo].shot();
					 ammo--;
				 }
				 else if (ammo <= 0)
				 {
					 STATE = Patrolling;
				 }
				 timeBetweenShots = timeToShot;
			 }
			 else
			 {
				 timeBetweenShots -= deltaTime;
			 }
			 canShot = false;
		 }
		
	}
	else
	{
		row = 0;
		animation.Update(row, deltaTime, faceRight);
		body.setTextureRect(animation.uvRect);
	}

}
sf::Vector2f Enemy::getPosition()
{
	return position;
}
void Enemy::setPosition(sf::Vector2f pos)
{
	body.setPosition(pos);
}
void Enemy::draw(sf::RenderWindow &window,Player &playerCharacter)
{
	for (int i = 0; i < 10; i++)
	{

			if (bullet[i].draw(window, faceRight, playerCharacter) == true)
			{
				playerCharacter.health -= 20;
					bullet[i] = erase;
			}
	
		}
	window.draw(body);
}
float Enemy::calculateDistance(sf::Vector2f playerPosition)
{
	return position.x - playerPosition.x;
}
