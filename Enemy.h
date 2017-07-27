#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include <iostream>
#include "Player.h"
#include "Bullet.h"
class Enemy
{
public:
	
	enum State
	{
		Patrolling,
		Shoots,
		Fights

	};
	State STATE;
	void setState(int TEMP);
	int getState();
	void Update(float deltaTime, sf::FloatRect boundingBox,sf::Vector2f playerPosition,Player &player, sf::RenderWindow &window);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void draw(sf::RenderWindow & window, Player &playerCharacter);
	~Enemy();
	sf::Sprite body;
	Bullet erase;
	sf::Texture texture;
	float speed;
	int health;
	int temp = 1;
	sf::Vector2f position;
	sf::FloatRect bodyBoundingBox;
	float calculateDistance(sf::Vector2f playerPosition);
	bool isGoingLeft = true;
	bool isGoingRight = false;
	float minX;
	float maxX;
	int row = 0;
	int ammo;

	bool onlyOne = true;
	bool faceRight = false;
	bool canShot = true;
	float timeToShot =0.7f;
	float timeBetweenShots =0;
	float timeToAttack = 0.2f;
	float timeBetweenAttacks = timeToAttack;
    	const static int maxBullets = 11;
	Bullet bullet[maxBullets];
	Animation animation;
	Enemy(std::string file, float speed, int health);
};

