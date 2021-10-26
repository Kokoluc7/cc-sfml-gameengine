#pragma once
#include "Tile.hh"
#include<iostream>
#include<fstream>

class TileGroup
{
private:
  std::ifstream* reader{};
  int sizeX{}, sizeY{};
  void GenerateTiles(sf::RenderWindow*& window, const char* textureUrl,
  float tileWidth, float tileHeight, float tileScale, int sizeX, int sizeY, const char* tileGroupUrl);
  std::vector<Tile*>* tiles;
public:
  TileGroup(sf::RenderWindow*& window, const char* textureUrl,
  float tileWidth, float tileHeight, float tileScale, int sizeX, int sizeY, const char* tileGroupUrl);
  ~TileGroup();
  void Draw();
};