#pragma once
#include<SFML/Graphics.hpp>
#include "TextAsset.hh"

class ButtonElement
{
private:
  float width{}, height{};
  float posX{}, posY{};
  sf::Color borderColor{};
  sf::Color fillColor{};
  float borderSize{};
  sf::RenderWindow* window{};

  TextAsset* textAsset{};

  sf::RectangleShape* buttonShape{};
public:
  ButtonElement(sf::RenderWindow*& window, float width, float height, float posX, float posY,
  sf::Color borderColor, sf::Color fillColor, float borderSize, const char* textUrl,
  const char* textMessage, sf::Color textColor);
  ~ButtonElement();

  void Draw();
  void Update();
};