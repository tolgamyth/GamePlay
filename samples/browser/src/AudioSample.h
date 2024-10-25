#pragma once

#include "SamplesGame.h"

using namespace gameplay;

class AudioSample : public Sample, Control::Listener
{
public:

  AudioSample();

protected:

  void initialize();

  void finalize();

  void update(float elapsedTime);

  void render(float elapsedTime);

  void controlEvent(Control* control, EventType evt);

private:

  Form* _formBackground;
  Form* _formEngine;
  Form* _formBraking;
  std::shared_ptr<AudioSource> _audioBackground;
  std::shared_ptr<AudioSource> _audioEngine;
  std::shared_ptr<AudioSource> _audioBraking;
};
