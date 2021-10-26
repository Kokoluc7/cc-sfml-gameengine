#include "Character.hh"
#include "InputSystem.hh"
#include "Animation.hh"


Animation* idleAnim{};
Animation* runAnim{};

Character::Character(){}

Character::Character(const char* textureUrl, sf::Vector2f position, float scale, float width,
float height, int col, int row, float moveSpeed, sf::RenderWindow*& window, b2World*& world) :
GameObject(textureUrl, position, scale, width, height, col, row, b2BodyType::b2_dynamicBody, window, world)
{
  this->moveSpeed = moveSpeed;

  rigidbody->FreezeRotation(true);

  idleAnim = new Animation(0.05f, 5, 0, 5, 16, 16, drawable);
  runAnim = new Animation(0.08f, 6, 0, 5, 16, 16, drawable);
}

Character::~Character()
{
}

void Character::Update(float& deltaTime)
{
  GameObject::Update(deltaTime);

  Movement(deltaTime);
  FlipSprite();

  if(std::abs(InputSystem::GetAxis().x) > 0 || std::abs(InputSystem::GetAxis().y) > 0)
  {
    runAnim->Play(deltaTime);
  }
  else
  {
    idleAnim->Play(deltaTime);
  }
}

void Character::Movement(float& deltaTime)
{
  rigidbody->MoveBody(new b2Vec2(InputSystem::GetAxis().x * moveSpeed,
  InputSystem::GetAxis().y * moveSpeed));
}

void Character::FlipSprite()
{
  drawable->GetSprite()->setScale(InputSystem::GetAxis().x < 0.f ? -drawable->GetScale() :
  InputSystem::GetAxis().x > 0.f ? drawable->GetScale() :
  drawable->GetSprite()->getScale().x, drawable->GetSprite()->getScale().y);
}