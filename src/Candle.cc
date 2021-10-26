#include "Candle.hh"

Candle::Candle(const char* textureUrl, sf::Vector2f position, 
float scale, float width, float height, int col, int row, 
sf::RenderWindow*& window, b2World*& world) :
GameObject(textureUrl, position, scale, width, height, col, row, b2BodyType::b2_staticBody, window, world)
{
  idleAnim = new Animation(0.05f, 3, 6, 11, 16, 16, drawable);
}

Candle::~Candle()
{
}

void Candle::Update(float& deltaTime)
{
  idleAnim->Play(deltaTime);
}