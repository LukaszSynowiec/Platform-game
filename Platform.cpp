#include "Platform.h"



Platform::Platform( sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setFillColor(sf::Color::Red);
	body.setPosition(position);
	boundingBox = body.getGlobalBounds();
}

Platform::~Platform()
{
}

void Platform::draw(sf::RenderWindow & window)
{
	window.draw(body);
}
sf::FloatRect Platform::getBoundingBox()
{
	boundingBox = body.getGlobalBounds();
	return boundingBox;
}

