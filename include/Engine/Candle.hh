#pragma once
#include "GameObject.hh"
#include "Animation.hh"
class Candle : public GameObject
{
private:
  Animation* idleAnim{};
public:
  Candle(const char* textureUrl, sf::Vector2f position, 
  float scale, float width, float height, int col, int row, 
  sf::RenderWindow*& window, b2World*& world);
  ~Candle();
  void Update(float& deltaTime) override;
};