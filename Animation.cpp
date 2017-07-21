#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

Animation::Animation( sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	uvRect.width =25;
	uvRect.height = 45;
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime,bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime-=switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;

		}
	}

	
	uvRect.top = currentImage.y*uvRect.height;

	if (faceRight)
	{
		uvRect.left = (currentImage.x + 1)*uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1)*abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}

