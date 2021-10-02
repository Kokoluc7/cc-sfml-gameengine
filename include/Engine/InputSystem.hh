#pragma once
#include<SFML/Graphics.hpp>

class InputSystem
{
private:

public:
  InputSystem();
  ~InputSystem();

  static sf::Vector2f GetAxis();
};