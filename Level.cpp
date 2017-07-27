#include "Level.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "Platform.h"
#include <string>
using namespace sf;
using namespace std;
Level::Level()
{

	width = 0;
	height = 0;

	startX = 0;
	startY = 0;
}


Level::~Level()
{
}


// Zwraca "true" je¿eli uda³o siê pomyœlnie wczytaæ plik
bool Level::loadFromFile(int levelNum)
{
	string filea = "data/level" + to_string(levelNum) + "/map.level";

	fstream file;
	file.open(filea,ios::in);

	if (!file.is_open())
	{
	return false;
	}
	

	// wczytywanie rozmiarów poziomu
	file >> width >> height;

	if (width == 0 || height == 0) {
		file.close();
		return false;
	}

	// ustawienie  rozmiar utablicy
	map.resize(height);

	for (int i = 0; i < height; i++) {
		map[i].resize(width);
	}

	// wczytanie textur
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			short buffer;

			file >> buffer;
			map[y][x] = getTile(buffer);
		}
	}

	file.close();
	return true;
}
// funkcja pomocnicza, zwraca Tile o odpowiednich w³aœciwoœciach
Level::Tile Level::getTile(short code)
{
	Tile tile;
	tile.type = TileType(code);

	switch (TileType(code))
	{
	case Level::PLATFORM:
		tile.collideable = true;
		tile.interactable = false;
		break;


	default:
		tile.collideable = false;
		tile.interactable = false;
		break;
	}

	return tile;
}
sf::Vector2f Level::setPositionFromFile(int levelnumber,string filename)
{


	if (levelnumber>10)
	{
		float tab[4];
		string filea = "data/level" + to_string(levelnumber-10) + "/" + filename + ".level";

		fstream file;
		file.open(filea, ios::in);
		file >> tab[0] >> tab[1] >> tab[2]>> tab[3];
		file.close();
		return sf::Vector2f(tab[2], tab[3]);
	}
	else
	{
		float x, y;
		string filea = "data/level" + to_string(levelnumber) + "/" + filename + ".level";

		fstream file;
		file.open(filea, ios::in);
		file >> x >> y;
		file.close();
		sf::Vector2f temp(x, y);
		return temp;
	}
}
std::vector<Platform> Level::loadPlatform(int levelnumber, string filename)
{
	std::vector<Platform>platform;

	float f1, f2, f3, f4;
	std::string filea = "data/level" + to_string(levelnumber) + "/" + filename + ".level";
	fstream file;
	file.open(filea, ios::in);		

while (!(file.eof()))
{
		file >> f1 >> f2 >> f3>>f4;
	
		platform.emplace_back(Platform(sf::Vector2f(f1,f2), sf::Vector2f(f3,f4)));
	}
	
	file.close();

	return platform;
}
