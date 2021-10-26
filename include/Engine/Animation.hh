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
  float width{};
  float height{};
  int currentFrame{};
  Drawable* drawable;
  float timer{};
public:
  Animation(float delay, int row, int startFrame, int endFrame, float width, float height, Drawable*& drawable);
  ~Animation();
  void Play(float& deltaTime);
};