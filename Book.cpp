#include "Book.h"
#include <SFML\Graphics.hpp>
#include <iostream>


Book::Book(std::string file,sf::Vector2f position)
{
	texture.loadFromFile("data/" + file);
	body.setTexture(texture);
	body.setScale(2, 2);
	body.setPosition(position);
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
