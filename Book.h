#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class Book
{
public:
	Book(std::string);
	~Book();
	bool can_draw = true;
	void draw(sf::RenderWindow & window);
	sf::Sprite body;
	sf::Texture texture;
	sf::Vector2f position;
	sf::Sprite getBook();
	void setPosition(sf::Vector2f pos);

};

