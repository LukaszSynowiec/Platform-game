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
	Ring(sf::Vector2f point);
	void load(std::string);
	sf::Sprite getRing();
	~Ring();
};

