#include "InputSystem.hh"

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

sf::Vector2f InputSystem::GetAxis()
{
  sf::Vector2f axis{};

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ||
  sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
  {
    axis.x = 1;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ||
  sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
  {
    axis.x = -1;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
  sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
  {
    axis.y = -1;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ||
  sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
  {
    axis.y = 1;
  }

  return axis;
}

sf::Vector2i InputSystem::GetMousePosition(sf::RenderWindow*& window)
{
  return sf::Mouse::getPosition(*window);
}

bool InputSystem::OnClick()
{
  return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool InputSystem::HoverUI(sf::RenderWindow*& window, sf::FloatRect floatRect)
{
  sf::Vector2f mousePos2Pixel{window->mapPixelToCoords(GetMousePosition(window))};
  return floatRect.contains(mousePos2Pixel);
}