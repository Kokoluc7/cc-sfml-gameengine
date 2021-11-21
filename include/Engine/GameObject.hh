#pragma once
#include<SFML/Graphics.hpp>
#include "Rigidbody.hh"
#include "Drawable.hh"
#include<string>


class GameObject
{
protected:
  Drawable* drawable{};
  sf::RenderWindow* window{};
  Rigidbody* rigidbody{};
  std::string  tagName{};
public:
  GameObject(const char* textureUrl, sf::Vector2f position, float scale, float width, float height, int col, int row,
  b2BodyType bodyType,sf::RenderWindow*& window, b2World*& world);
  ~GameObject();

  void SetTagtName(std::string  tagName);
  std::string GetTagName() const;

  virtual void Update(float& deltaTime);
  virtual void Draw();

  sf::Vector2f GetPosition() const;
};