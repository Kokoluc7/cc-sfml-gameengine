#include "TextAsset.hh"

TextAsset::TextAsset(sf::RenderWindow*& window, const char* fontUrl, 
const sf::String message, float size, sf::Color color, sf::Vector2f position)
{
  this->window = window;
  font = new sf::Font();
  font->loadFromFile(fontUrl);
  text = new sf::Text(message, *font, sf::Text::Bold);
  text->setFillColor(color);
  text->setCharacterSize(size);
  text->setPosition(position);
}

TextAsset::~TextAsset()
{
}

void TextAsset::Draw()
{
  window->draw(*text);
}