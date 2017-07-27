#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
class Ring
{
public:
	sf::Texture texture;
	sf::Sprite ring;
	sf::Vector2f position;
	sf::Vector2f pointPosition;

	bool draw_ring;
	void draw(sf::RenderWindow &window);
	Ring();
	void setPosition(sf::Vector2f pos);
	void load(std::string);
	sf::Sprite getRing();
	~Ring();
};

