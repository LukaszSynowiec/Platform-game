#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Animation.h"
#include "Game.h"
#include <string>


Player::Player(sf::Texture &playerTexture,sf::Vector2u imageCount, float switchTime)
{
	
	row = 0;
	faceRight = true;
	playerChar.setTexture(playerTexture);
playerChar.setPosition(0, 768 - (64 + 45));

	State = Start;
	health = 100;
}

Player::~Player() 
{
}
void Player::Update(float deltaTime,Animation &animation,Player &playerCharacter,sf::RenderWindow &window)
{
	window.setMouseCursorVisible(false);

	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= playerCharacter.Speed*deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += playerCharacter.Speed*deltaTime;
	}
	if (State==Jumping)
	{
		//83 px-wysokosc skoku
		movement.y -= (jumpStrength+Speed )*deltaTime;
		if (jumpStrength <= 130)
			jumpStrength--;
		if(jumpStrength==0)
		{
			State = Falling;
			jumpStrength = 130;
		}
		animation.currentImage.x = 3;
		animation.currentImage.y = 3;
	}
	if (State == Falling)
	{
		movement.y += ((playerCharacter.Speed*gravity)/4)*deltaTime;
		animation.currentImage.x = 5;
		animation.currentImage.y = 3;
	}
	if (movement.x == 0.0)
	{
		if (movement.x == 0.0&&movement.y == 0.0)
		{
			animation.currentImage.x =6;
			animation.currentImage.y = 0;
		}
		row = 0;
	}
	else
	{
		row = 1;
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
		playerCharacter.playerChar.setTextureRect(animation.uvRect);
		animation.Update(row, deltaTime, faceRight);
		playerCharacter.playerChar.move(movement);
		if (getPosition().y >= 768 - (64 + 45))
		{
			State = onGround;
		}
		if (State == onSky)
		{
			State = Falling;
		}
}
sf::Sprite Player::getSprite() const 
{
	return playerChar;
}
void Player::setSpeed(float TEMP_Speed)
{
	Speed = TEMP_Speed;
}
sf::Vector2f Player::getPosition()
{
	return playerChar.getPosition();
}

void Player::setPosition(float x, float y)
{
	playerChar.setPosition(sf::Vector2f(x, y));
}

void Player::setJumpStrength(float jump)
{
	jumpStrength = jump;
}
