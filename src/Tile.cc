#include "Tile.hh"

Tile::Tile(const char* textureUrl, sf::Vector2f position, float scale, float width, float height, int col, int row, sf::RenderWindow*& window) :
Drawable(textureUrl, position, scale, width, height, col, row)
{
  this->window = window;
}

Tile::~Tile()
{
}

void Tile::Draw()
{
  window->draw(*Drawable::GetSprite());
}