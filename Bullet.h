#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>
#include "Animation.h"
#include "Player.h"
class Bullet
{
public:

	Bullet();
	~Bullet();
	void shot();
	bool canDraw = false;
	bool oneCheck = false;
	enum DIRECTION
	{
		LEFT,
		RIGHT
	};
	DIRECTION Dir;
	sf::CircleShape body;
	sf::Vector2f position;
	float speed;
	void setPosition(sf::Vector2f pos);
	bool draw(sf::RenderWindow & window, bool faceRight,Player &playerCharacter);

};


