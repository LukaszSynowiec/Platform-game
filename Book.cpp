#include "Book.h"
#include <SFML\Graphics.hpp>
#include <iostream>


Book::Book(std::string file)
{
	texture.loadFromFile("data/" + file);
	body.setTexture(texture);
	body.setScale(2, 2);

}


Book::~Book()
{
}

void Book::draw(sf::RenderWindow &window)
{
	if(can_draw)
	window.draw(body);
}

sf::Sprite Book::getBook()
{
	return body;
}

void Book::setPosition(sf::Vector2f pos)
{
	body.setPosition(pos);
}
