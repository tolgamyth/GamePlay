#pragma once

namespace gameplay
{

class AudioListener;
class AudioSource;

/**
 * Defines a class for controlling game audio.
 */
class AudioController
{
    friend class Game;
    friend class AudioSource;

public:

  /**
   * Constructor.
   */
  AudioController();
    
  /**
    * Destructor.
    */
  virtual ~AudioController();

private:

    /**
     * Controller initialize.
     */
    void initialize();

    /**
     * Controller finalize.
     */
    void finalize();

    /**
     * Controller pause.
     */
    void pause();

    /**
     * Controller resume.
     */
    void resume();

    /**
     * Controller update.
     */
    void update(float elapsedTime);

    void addPlayingSource(std::shared_ptr<AudioSource> source);
    
    void removePlayingSource(std::shared_ptr<AudioSource> source);

    static void streamingThreadProc(void* arg);

    ALCdevice* _alcDevice;
    ALCcontext* _alcContext;
    std::set<std::shared_ptr<AudioSource>> _playingSources;
    std::set<std::shared_ptr<AudioSource>> _streamingSources;
    std::shared_ptr<AudioSource> _pausingSource;

    bool _streamingThreadActive;
    std::unique_ptr<std::thread> _streamingThread;
    std::unique_ptr<std::mutex> _streamingMutex;
};

}
