#include "Ring.h"
#include <SFML\Graphics.hpp>
#include <iostream>


Ring::Ring(sf::Vector2f point)
{
	pointPosition= point;

	draw_ring = false;
}
void Ring::load(std::string file)
{
	texture.loadFromFile("data/" + file);
	ring.setTexture(texture);
	ring.setScale(2, 2);
	ring.setPosition(pointPosition);
}
sf::Sprite Ring::getRing()
{
	return ring;
}
void Ring::draw(sf::RenderWindow &window)
{
	if(draw_ring)
	window.draw(ring);
}
Ring::~Ring()
{
}
