#include "../../HeaderFiles/Sound/SoundService.h"
#include "../../HeaderFiles/Global/config.h"
#include <iostream>
using namespace std;

namespace Sound
{
	using namespace Global;

	SoundService::SoundService()
	{

	}

	SoundService::~SoundService()
	{

	}

	void SoundService::initialize()
	{
		loadBackgroundMusic();
		loadSoundEffects();
	}

	void SoundService::loadBackgroundMusic()
	{
		if (!backgroundMusic.openFromFile(Config::backgroundMusicPath))
		{
			cout << "Eror while loading background music file " << endl;
		}
	}

	void SoundService::loadSoundEffects()
	{
		if (!buttonClick.loadFromFile(Config::buttonclickSoundPath))
		{
			cout << "Error while loading button click sound file " << endl;
		}
	}

	void SoundService::playBackgroundMusic()
	{
		backgroundMusic.setLoop(true);
		backgroundMusic.setVolume(backgroundMusicVolume);
		backgroundMusic.play();
	}

	void SoundService::playSound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTONCLICK:
			soundEffects.setBuffer(buttonClick);
			break;
		default:
			cout << "Invalid sound type" << endl;
			return;
		}

		soundEffects.play();
	}

}