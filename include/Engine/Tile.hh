#pragma once
#include<SFML/Graphics.hpp>
#include "Drawable.hh"

class Tile : public Drawable
{
private:
  sf::RenderWindow* window{};
public:
  Tile(const char* textureUrl, sf::Vector2f position, float scale, float width, float height, int col, int row, sf::RenderWindow*& window);
  ~Tile();
  void Draw();
};