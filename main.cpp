#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Game.h"
#include "Player.h"
#include "Animation.h"
#include "Platform.h"
#include "Menu.h"
using namespace std;
const int x=7, y=0;
void setPlatforms(std::vector<Platform>&platform);
int main()
{
	static	sf::Texture tex;
	tex.loadFromFile("data/charzera.png");
	static	Animation animation(sf::Vector2u(x,y), 0.1f);
	static	Player playerCharacter(tex, sf::Vector2u(x,y), 0.3f);
	playerCharacter.setSpeed(120);
	playerCharacter.setJumpStrength(130);
	std::vector<Platform>platform;
	setPlatforms(platform);	
	Game game;
	game.setHowMuchPlatforms(15);
	game.start(animation,playerCharacter,platform);

	return 0;
}

void setPlatforms(std::vector<Platform>&platform)
{
	// HOW_MUCH_PLATFORMS =15
	//--------------------------------
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(350.0f, 560.0f)));
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(100.0f, 500.0f)));
	platform.emplace_back(Platform(sf::Vector2f(70.0f, 14.0f), sf::Vector2f(200.0f, 500.0f)));
	platform.emplace_back(Platform(sf::Vector2f(200.0f, 14.0f), sf::Vector2f(500.0f, 500.0f)));
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(600.0f, 420.0f)));
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(200.0f, 640.0f)));
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(450.0f, 360.0f)));
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(250.0f, 320.0f)));
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(70.0f, 240.0f)));
	//pod pierœcieniem ma³y
	platform.emplace_back(Platform(sf::Vector2f(20.0f, 14.0f), sf::Vector2f(140.0f,180.0f)));
	//góra 5 ko³o siebie
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(285.0f,130.0f)));
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(510.0f, 130.0f)));
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(735.0f, 130.0f)));
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(960.0f,130.0f)));
	platform.emplace_back(Platform(sf::Vector2f(150.0f, 14.0f), sf::Vector2f(1185.0f, 130.0f)));
	//--------------------------------------
}