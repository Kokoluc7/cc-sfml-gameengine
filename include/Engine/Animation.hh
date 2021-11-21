#pragma once

#include<SFML/Graphics.hpp>
#include "Drawable.hh"

class Animation
{
private:
 float delay{};
  int row{};
  int startFrame{};
  int endFrame{};
  int currentFrame{};
  Drawable* drawable;
  float timer{};

  std::ifstream* reader{};
public:
  Animation(const char* animationUrl, Drawable*& drawable);
  ~Animation();
  void Play(float& deltaTime);
};