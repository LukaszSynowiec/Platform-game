#pragma once
#include "SFML\Graphics.hpp"
class Platform
{
public:
	Platform(sf::Vector2f size,sf::Vector2f position);
	~Platform();
	void draw(sf::RenderWindow &window);
	sf::FloatRect boundingBox;
	sf::RectangleShape body;
	sf::FloatRect getBoundingBox();
};

