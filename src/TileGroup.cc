#include "TileGroup.hh"

TileGroup::TileGroup(sf::RenderWindow*& window, const char* textureUrl,
float tileWidth, float tileHeight, float tileScale, int sizeX, int sizeY, const char* tileGroupUrl)
{
  reader = new std::ifstream();
  tiles = new std::vector<Tile*>();
  GenerateTiles(window, textureUrl, tileWidth, tileHeight, tileScale, sizeX, sizeY, tileGroupUrl);
}

TileGroup::~TileGroup()
{
}

void TileGroup::GenerateTiles(sf::RenderWindow*& window, const char* textureUrl,
float tileWidth, float tileHeight, float tileScale, int sizeX, int sizeY, const char* tileGroupUrl)
{

  reader->open(tileGroupUrl);

  for(int y{}; y < sizeY; y++)
  {
    for(int x{}; x < sizeX; x++)
    {
      int col{}, row{};
      int currentCharater{};

      *reader >> currentCharater;
      col = currentCharater;

      *reader >> currentCharater;
      row = currentCharater;

      tiles->push_back(new Tile(textureUrl, sf::Vector2f(tileWidth * x * tileScale, tileHeight * y * tileScale),
      tileScale, tileWidth, tileHeight, col, row, window));
    }
    std::cout << std::endl;
  }

  reader->close();
}

void TileGroup::Draw()
{
  for(auto& tile : *tiles)
  {
    tile->Draw();
  }
}