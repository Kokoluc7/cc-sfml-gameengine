#include "ButtonElement.hh"
#include "InputSystem.hh"
#include<iostream>

ButtonElement::ButtonElement(sf::RenderWindow*& window, float width, float height, float posX, float posY,
sf::Color borderColor, sf::Color fillColor, float borderSize, const char* textUrl,
const char* textMessage, sf::Color textColor)
{
  this->window = window;
  this->width = width;
  this->height = height;
  this->posX = posX;
  this->posY = posY;
  this->fillColor = fillColor;
  this->borderColor = borderColor;
  this->borderSize = borderSize;

  buttonShape = new sf::RectangleShape();
  buttonShape->setFillColor(fillColor);
  buttonShape->setOutlineColor(borderColor);
  buttonShape->setPosition(posX, posY);
  buttonShape->setSize(sf::Vector2f(width, height));
  buttonShape->setOutlineThickness(borderSize);

  textAsset = new TextAsset(window, textUrl, textMessage, (width / height) * 10, textColor,
  sf::Vector2(posX + width / 2, posY + height / 2));

  textAsset->SetOrigin(width / 2, height / 2);
}

ButtonElement::~ButtonElement()
{
}

void ButtonElement::Update()
{
  if(InputSystem::HoverUI(window, buttonShape->getGlobalBounds()) && InputSystem::OnClick())
  {
    std::cout << "button click" << std::endl;
  }
}

void ButtonElement::Draw()
{
  window->draw(*buttonShape);
  textAsset->Draw();
}