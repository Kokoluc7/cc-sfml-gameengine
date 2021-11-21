#include "AnimationsManager.hh"

AnimationsManager::AnimationsManager()
{
  animations = new std::map<std::string, Animation*>();
}

AnimationsManager::~AnimationsManager()
{
}

Animation* AnimationsManager::GetAnimation(std::string animationName) const
{
  return animations->at(animationName);
}
void AnimationsManager::AddAnimation(std::string animationName, Animation* animation)
{
  animations->insert({animationName, animation});
}
void AnimationsManager::Play(std::string animationName)
{
  GetAnimation(animationName)->Play(deltaTime);
}

void AnimationsManager::Update(float& deltaTime)
{
  this->deltaTime = deltaTime;
}