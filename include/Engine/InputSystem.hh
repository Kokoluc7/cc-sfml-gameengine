#pragma once
#include<SFML/Graphics.hpp>

class InputSystem
{
private:

public:
  InputSystem();
  ~InputSystem();

  static sf::Vector2f GetAxis();
  static bool HoverUI(sf::RenderWindow*& window, sf::FloatRect floatRect);
  static sf::Vector2i GetMousePosition(sf::RenderWindow*& window);
  static bool OnClick();
};