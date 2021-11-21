#include "AudioClip.hh"

AudioClip::AudioClip(const char* audioUrl, float volume)
{
  soundBuffer = new sf::SoundBuffer();
  sound = new sf::Sound();

  soundBuffer->loadFromFile(audioUrl);
  sound->setBuffer(*soundBuffer);
  sound->setVolume(volume);
}

AudioClip::~AudioClip()
{
}

void AudioClip::Play()
{
  sound->play();
}