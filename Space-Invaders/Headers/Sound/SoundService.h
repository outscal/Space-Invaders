#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
	};

	class SoundService
	{
	private:
		const int background_music_volume = 30;

		sf::Music background_music;
		sf::Sound sound_effect;
		sf::SoundBuffer buffer_button_click;

		void LoadBackgroundMusicFromFile();
		void LoadSoundFromFile();

	public:
		void Initialize();

		void PlaySound(SoundType soundType);
		void PlayBackgroundMusic();
	};
}
