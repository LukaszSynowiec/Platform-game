#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
using namespace sf;
using namespace std;
class Level
{
public:
	Level();
	~Level();
	bool loadFromFile(int levelNum);

	enum TileType
	{
		GRASS,SKY,PLATFORM,COUNT
	};

	struct Tile
	{
	public:

		TileType type;
		string interaction;

		bool collideable;
		bool interactable;
	};

	vector < vector <Tile > > map;

	unsigned short startX;
	unsigned short startY;


	unsigned short width;           // szerokosæ poziomu w kaflach (max 
	unsigned short height;          // wysokoœæ poziomu w kaflach

	Tile getTile(short);
	sf::Vector2f setPositionFromFile(int levelnumber, string filename);
	std::vector<Platform> loadPlatform(int levelnumber, string filename);
};


