#pragma once
#include <SFML/Audio.hpp>

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK
	};

	class SoundService
	{
	public:
		SoundService();
		~SoundService();

		void playSound(SoundType type);
		void backgroundSound();

		void initialize();

	private:
		const int volume = 30;
		sf::Music background_music;
		sf::Sound sound_effect;
		sf::SoundBuffer sound_effect_buffer;

		void loadBackgroundMusic();
		void loadSoundMusic();
	};

}
