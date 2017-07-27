#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Level.h"
#include "Player.h"
#include "Animation.h"
#include "Platform.h"
#include "Ring.h"
#include "Book.h"
#include "Enemy.h"
#include "Menu.h"
using namespace sf;
using namespace std;
class Game
{
public:
	enum STATE
	{
		MENU,
		GAME,
		OPTIONS,
		END
	};
	STATE State;
	~Game();
	void start(Animation &animation,Player &playerCharacter);
	void draw(Player &playerCharacter,vector < Platform >& tablica);
	void update(float, Animation &animation, Player &playerCharacter, vector < Platform >& tablica);
	void setMap(int);
	void updateMap();
	void setHowMuchPlatforms(int x);
	Menu menu;
	sf::Text healthText,endText;
	sf::Font font;
	sf::RenderWindow window;
	sf::View view;
    int HOW_MUCH_PLATFORMS;
	int WIDTH;
	int HEIGHT;
	float SCRN_WIDTH=1280;
	float SCRN_HEIGHT=768;
	float TILE_SIZE = 64;
	bool LEVEL_END;
	bool WIN_A_LEVEL = false;
	int books = 2, xd = 1,x=1;
	int bookX = 1;
	int bookY = 1;
	sf::Texture texture[Level::COUNT];
	sf::Texture doorTextureOpen,doorTextureClose;
	sf::Sprite door;
	Ring ring;
	Enemy enemy;
	Level level;
	Book book1,book2;
	std::vector<vector<Sprite>>sprite;
	Game();
};

