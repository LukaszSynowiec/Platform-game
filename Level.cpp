#include "Level.h"
#include <vector>
#include <fstream>
#include <iostream>
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
bool Level::loadFromFile(string level_name)
{
	fstream file;
	file.open("data/" + level_name,ios::in);

	if (!file.is_open())
		return false;

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
