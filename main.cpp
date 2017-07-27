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

int main()
{
	static	sf::Texture tex;
	tex.loadFromFile("data/charzera.png");
	static	Animation animation(sf::Vector2u(x,y), 0.1f);
	static	Player playerCharacter(tex, sf::Vector2u(x,y), 0.3f);
	playerCharacter.setSpeed(120);
	playerCharacter.setJumpStrength(130);


	Game game;
	game.setHowMuchPlatforms(15);
	game.start(animation,playerCharacter);

	return 0;
}

