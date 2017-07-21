#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#pragma once
class Animation
{
public:
	Animation( sf::Vector2u imageCount, float switchTime);
	~Animation();
	void Update(int row, float deltaTime, bool faceRight);

	sf::IntRect uvRect;

	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float totalTime;
	float switchTime;
};

