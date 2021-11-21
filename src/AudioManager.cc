#include "AudioManager.hh"

AudioManager::AudioManager()
{
  audioClips = new std::map<std::string, AudioClip*>();
}

AudioManager::~AudioManager()
{
}

AudioClip* AudioManager::GetAudioClip(std::string audioName) const
{
  return audioClips->at(audioName);
}
void AudioManager::AddAudioClip(std::string audioName, AudioClip* audioClip)
{
  audioClips->insert({audioName, audioClip});
}
void AudioManager::Play(std::string audioName)
{
  GetAudioClip(audioName)->Play();
}