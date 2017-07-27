#include "Ring.h"
#include <SFML\Graphics.hpp>
#include <iostream>


Ring::Ring()
{


	draw_ring = false;
}
void Ring::setPosition(sf::Vector2f pos)
{
	ring.setPosition(pos);
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
