#include "Animation.hh"

Animation:: Animation(float delay, int row,int startFrame, int endFrame, float width, float height, Drawable*& drawable)
{
  this->delay = delay;
  this->row = row;
  this->startFrame = startFrame;
  this->endFrame = endFrame;
  this->width = width;
  this->height = height;
  currentFrame = startFrame;
  this->drawable = drawable;
}

Animation::~Animation()
{
}

void Animation::Play(float& deltaTime)
{
  timer += deltaTime;
  if(timer >= delay)
  {
    drawable->RebindRect(currentFrame * width, row * height, width, height);
    //cambiar de frame
    timer = 0.f;
    if(currentFrame < endFrame)
    {
      currentFrame++;
    }
    else
    {
      currentFrame = startFrame;
    }
  }
}