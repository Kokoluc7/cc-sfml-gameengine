#include "Candle.hh"

Candle::Candle(const char* textureUrl, sf::Vector2f position,
float scale, float width, float height, int col, int row,
sf::RenderWindow*& window, b2World*& world) :
GameObject(textureUrl, position, scale, width, height, col, row, b2BodyType::b2_staticBody, window, world)
{
  animationsManager = new AnimationsManager();

  animationsManager->AddAnimation("idle", new Animation("assets/animations/candle/idle2.anim", drawable));
}

Candle::~Candle()
{
}

void Candle::Update(float& deltaTime)
{
  animationsManager->Update(deltaTime);

  animationsManager->Play("idle");
}