#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include "Animation.h"
class Player
{
public:
	Player(sf::Texture &playerTexture,sf::Vector2u imageCount, float switchTime); //Overload Constructor
	~Player(); //Destructor
	enum STATE
	{
		onGround,
		onPlatform,
		Falling,
		Jumping,
		Start,
		onSky
	};
	STATE State;
	int health;
	void setSpeed(float);
	void Update(float, Animation &animation, Player &playerCharacter, sf::RenderWindow &window);
	sf::Sprite getSprite() const;
	sf::Texture playerTexture;
	sf::Vector2f getPosition();
	void setPosition(float x,float y);
	sf::Sprite playerChar; 
	void setJumpStrength(float);
	unsigned int row;
	bool faceRight;
	float jumpStrength =130;
	float gravity = 9.8f;
	sf::FloatRect boundingBox;
	float Speed;
	sf::Clock AnimClock;
	sf::Time AnimTime;
	
};

