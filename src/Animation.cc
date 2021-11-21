#include "Animation.hh"

Animation:: Animation(const char* animationUrl, Drawable*& drawable)
{
  reader = new std::ifstream();

  readear->open(animationUrl);
  *reader >> delay;
  *reader >> row;
  *reader >> startFrame;
  *reader >> endFrame;
  reader->close();

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
    drawable->RebindRect(currentFrame * drawable->GetWidth(), row * drawable->GetHeight(), drawable->GetWidth(), drawable->GetHeight());
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