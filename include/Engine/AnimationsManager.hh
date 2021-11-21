#pragma once

#include "Animation.hh"
#include<map>
#include<string>

class AnimationsManager
{
private:
  std::map<std::string, Animation*>* animations;
  float deltaTime{};
public:
  AnimationsManager();
  ~AnimationsManager();

  Animation* GetAnimation(std::string animationName) const;
  void AddAnimation(std::string animationName, Animation* animation);
  void Play(std::string animationName);
  void Update(float& deltaTime);
};