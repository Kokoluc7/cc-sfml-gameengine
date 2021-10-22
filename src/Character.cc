#include "Character.hh"
#include "InputSystem.hh"
#include "Animation.hh"


//sf::CircleShape* circle{new sf::CircleShape()};

Animation* idleAnim{};
Animation* runAnim{};

Character::Character(){}

Character::Character(const char* textureUrl, sf::Vector2f position, float scale, float width, 
float height, int col, int row, float moveSpeed, sf::RenderWindow*& window)
{
  this->position = position;
  this->scale = scale;
  this->width = width;
  this->height = height;
  this->width = width;
  this->window = window;
  this->moveSpeed = moveSpeed;
  //this->textureUrl = textureUrl;
  //std::cout << this->textureUrl << std::endl;
  texture = new sf::Texture();
  texture->loadFromFile(textureUrl);
  sprite = new sf::Sprite(*texture, sf::IntRect(col * width, row * height, width, height));
  sprite->setPosition(position);
  sprite->setScale(sf::Vector2f(scale, scale));
  sprite->setColor(sf::Color::White);
  sprite->setOrigin(sprite->getLocalBounds().width / 2.f, sprite->getLocalBounds().height / 2.f);

  idleAnim = new Animation(0.05f, 5, 0, 5, 16, 16, sprite);
  runAnim = new Animation(0.08f, 6, 0, 5, 16, 16, sprite);
  //circle->setRadius(2.f);
  //circle->setFillColor(sf::Color::Green);
  //circle->setOutlineColor(sf::Color::Green);
}

Character::~Character()
{
}

void Character::Draw()
{
  window->draw(*sprite);
  //circle->setPosition(sprite->getPosition());
  //window->draw(*circle);
}

void Character::Movement(float& deltaTime)
{
  sprite->move(InputSystem::GetAxis() * deltaTime * moveSpeed);
  FlipSprite();
  //si estoy pulsando las teclas de movimiento ?
  if(std::abs(InputSystem::GetAxis().x) > 0 || std::abs(InputSystem::GetAxis().y) > 0)
  {
    runAnim->Play(deltaTime);
  }
  else //si no me estoy moviendo
  {
    idleAnim->Play(deltaTime);
  }
}

void Character::FlipSprite()
{
  sprite->setScale(InputSystem::GetAxis().x < 0.f ? -scale : 
  InputSystem::GetAxis().x > 0.f ? scale :
  sprite->getScale().x, sprite->getScale().y);
}