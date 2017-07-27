#include "Game.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <string>
#include <cstdio>
using namespace sf;
using namespace std;
Game::Game():
	ring({ 123,45 }), 
	book1("book.png",{1180,70}),
	book2("book.png", { 30,150 }),
	enemy(("enemy.png"),100,100,{1000,60}),
	menu(1280,768)
{
	State = MENU;
	font.loadFromFile("data/font.ttf");
	healthText.setFont(font);
	healthText.setPosition(0, 0);
	healthText.setFillColor(sf::Color::Red);
	healthText.setCharacterSize(40);
	endText.setFont(font);
	endText.setCharacterSize(70);
	endText.setFillColor(sf::Color::White);
	doorTextureClose.loadFromFile("data/doorClose.png");
	doorTextureOpen.loadFromFile("data/doorOpen.png");
	door.setTexture(doorTextureClose);
	door.setPosition(SCRN_WIDTH - 54, (SCRN_HEIGHT - 64) - 97);
	LEVEL_END = false;
	window.create(VideoMode(SCRN_WIDTH, SCRN_HEIGHT), "Platformówka", Style::Close);
	view.setSize(SCRN_WIDTH, SCRN_HEIGHT);
	view.setCenter(SCRN_WIDTH/2,SCRN_HEIGHT/2);

		for (int x = 0,i=0; x < 3; x++)
		{
			texture[i].loadFromFile("data/tileset.png", IntRect(Vector2i(TILE_SIZE*x, 0), Vector2i(TILE_SIZE, TILE_SIZE)));
			i++;
		}
	WIDTH = window.getSize().x / TILE_SIZE ;
	HEIGHT = window.getSize().y / TILE_SIZE;
	Sprite standard(texture[0]);
	sprite.resize(HEIGHT);
	for (int y = 0; y < HEIGHT; y++) {
		sprite[y].resize(WIDTH, standard);
	}
	ring.load("ring.png");
	setMap("map.level");
}
Game::~Game()
{
}
void Game::start(Animation &animation, Player &playerCharacter, vector < Platform >& tablica)
{


	ring.draw_ring = false;
	Time lastUpdate = Time::Zero;
	Clock time;
	window.setView(view);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape&&State!=OPTIONS)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				if(State==GAME)
				{ 
					if (playerCharacter.State != static_cast <Player::STATE>(3) && playerCharacter.State != static_cast <Player::STATE>(2))
						playerCharacter.State = static_cast <Player::STATE>(3);
				}
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up&&State == MENU)
			{
				menu.MoveUp();
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down&&State == MENU)
			{
				menu.MoveDown();
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return&&State == MENU)
			{
				switch (menu.GetPressedItem())
				{
				case 0:
				{
					State = GAME;

				}
				break;
				case 1:
				{
					State = OPTIONS;
				}
				break;
				case 2:
				{
				window.close();
				}
					break;
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape&&State == OPTIONS)
			{
				State = MENU;
			}
		}
		if (State == MENU)
		{
			endText.setCharacterSize(15);
			endText.setString("Next levels soon");
			endText.setPosition({ SCRN_WIDTH / 2 - (endText.getGlobalBounds().width / 2),15 });
			window.clear(sf::Color::Black);
			window.draw(endText);
			menu.Draw(window);
			window.display();
		}
		if (State == GAME)
		{
			
			float delta = time.getElapsedTime().asSeconds() - lastUpdate.asSeconds();//czas pomiêdzy klatkami
			enemy.Update(delta, playerCharacter.getSprite().getGlobalBounds(), playerCharacter.getPosition(), playerCharacter, window);
			update(delta, animation, playerCharacter, tablica);
			lastUpdate = time.getElapsedTime();
			if (x == 1)
			{
				sf::Vector2f pos(1000, 60);
				enemy.setPosition(pos);

				x = 0;
			}
			draw(playerCharacter, tablica);
		}
		if (State == END)
		{
			endText.setCharacterSize(70);
			if (WIN_A_LEVEL)
			{
				endText.setString("WINNER");
				endText.setPosition({ SCRN_WIDTH / 2 - (endText.getGlobalBounds().width / 2),300});
			}
			else
			{
				endText.setString("LOOSER");
				endText.setPosition({ SCRN_WIDTH / 2 - (endText.getGlobalBounds().width / 2),300});
			}
			window.clear(sf::Color::Black);
			window.draw(endText);
			window.display();

		}
		if (State == OPTIONS)
		{
			endText.setCharacterSize(70);
		endText.setString("SOON");
				endText.setPosition({ SCRN_WIDTH / 2 - (endText.getGlobalBounds().width / 2),300 });
			window.clear(sf::Color::Black);
			window.draw(endText);
			window.display();
		}
	}	
}
void Game::update(float delta, Animation &animation, Player &playerCharacter, vector < Platform >& tablica)
{
	if (playerCharacter.health <= 0)
	{
		WIN_A_LEVEL = false;
		State = END;
	}

	sf::Vector2f pointDown;
	pointDown.x = playerCharacter.getPosition().x+13;
	pointDown.y = playerCharacter.getPosition().y + 45;
	sf::Vector2f pointUp;
	pointUp.x = playerCharacter.getPosition().x + 12;
	pointUp.y = playerCharacter.getPosition().y;
	if(books==0)
	{
		if (LEVEL_END==false)
		{
			ring.draw_ring = true;
			
		}
		if (playerCharacter.playerChar.getGlobalBounds().intersects(ring.getRing().getGlobalBounds()))
		{
			ring.draw_ring = false;
			door.setTexture(doorTextureOpen);
			LEVEL_END = true;
		}
	}
	if (playerCharacter.playerChar.getGlobalBounds().intersects(book1.getBook().getGlobalBounds())&&bookX==1)
	{
		book1.can_draw = false;
		book1.body.setPosition(0, 0);
		books--;
		bookX = 0;

	}
	if (playerCharacter.playerChar.getGlobalBounds().intersects(book2.getBook().getGlobalBounds()) && bookY == 1)
	{
		book2.can_draw = false;
		book2.body.setPosition(0, 0);
		books--;
		bookY = 0;

	}
	if (playerCharacter.playerChar.getGlobalBounds().intersects(door.getGlobalBounds())&&LEVEL_END==true)
	{
		State = END;
		WIN_A_LEVEL = true;
	}
	if (playerCharacter.getPosition().x<0)
	{
		playerCharacter.setPosition(0, playerCharacter.getPosition().y);
	}
	if (playerCharacter.getPosition().x>=SCRN_WIDTH-25)
	{
		playerCharacter.setPosition(SCRN_WIDTH-25, playerCharacter.getPosition().y);
	}
	if (playerCharacter.getPosition().y<0)
	{
		playerCharacter.State = static_cast < Player::STATE >(2);
		playerCharacter.setJumpStrength(130);
	}
	for (int i = 0; i < HOW_MUCH_PLATFORMS; i++)
	{
		if (tablica[i].getBoundingBox().contains(pointUp))
		{
			playerCharacter.State = static_cast < Player::STATE >(2);
			playerCharacter.setJumpStrength(130);
		
		}
		if (tablica[i].getBoundingBox().contains(pointDown))
		{
			if (playerCharacter.State != static_cast <Player::STATE>(3))
			{
				playerCharacter.State = static_cast <Player::STATE>(1);
			}
		}
		else if (playerCharacter.State == static_cast <Player::STATE>(1))
		{
			playerCharacter.State = static_cast < Player::STATE >(5);
		}
			
	
	for (int i = 0; i < HOW_MUCH_PLATFORMS; i++)
	{
		if (tablica[i].getBoundingBox().contains(pointDown))
		{

			if (playerCharacter.State != static_cast <Player::STATE>(3))
			{
				playerCharacter.State = static_cast <Player::STATE>(1);
			}
		}
	}
}
	playerCharacter.Update(delta,animation,playerCharacter,window);
	healthText.setString("Health:" + to_string(playerCharacter.health));
}
// draw all elements
void Game::draw(Player &playerCharacter, vector < Platform >& tablica)
{
	window.clear();
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			window.draw(sprite[y][x]);
		}
	}
	for (int i = 0; i < HOW_MUCH_PLATFORMS; i++)
	{
		tablica[i].draw(window);
	}
	book1.draw(window);
	book2.draw(window);
	window.draw(door);
	enemy.draw(window,playerCharacter);
	window.draw(playerCharacter.getSprite());
	ring.draw(window);
	window.draw(healthText);
	window.display();
}
void Game::setMap(string name)
{
	if (!level.loadFromFile(name)) {
		cout << "[ERROR] 404 File not found";
		return;
	}
	
	updateMap();
	window.setView(view);
}

void Game::updateMap()
{
	// set the tiles on the scene
	for (int y = 0, h = 0; y < HEIGHT; y++) {          // h - horizontal
		for (int x = 0, v = 0; x < WIDTH; x++)       // v - vertical
		{
			sprite[y][x].setPosition(v*TILE_SIZE, h*TILE_SIZE);
			sprite[y][x].setTexture(texture[level.map[h][v].type]);
			v++;
		}
		h++;
	}
}
void Game::setHowMuchPlatforms(int x)
{
	HOW_MUCH_PLATFORMS = x;
}
