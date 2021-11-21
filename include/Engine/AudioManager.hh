#pragma once
#include "AudioClip.hh"
#include<map>
#include<string>

class AudioManager
{
private:
  std::map<std::string, AudioClip*>* audioClips;
public:
  AudioManager();
  ~AudioManager();

  AudioClip* GetAudioClip(std::string audioName) const;
  void AddAudioClip(std::string audioName, AudioClip* audioClip);
  void Play(std::string audioName);
};