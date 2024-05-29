#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Sound\SoundService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\Config.h"

namespace Sound
{
	using namespace Global;

	void SoundService::Initialize()
	{
		LoadBackgroundMusicFromFile();
		LoadSoundFromFile();
	}

	void SoundService::LoadBackgroundMusicFromFile()
	{
		if (!background_music.openFromFile(Config::background_music_path)) //if this returns true then print error
			printf("Error loading background music file");
	}

	void SoundService::LoadSoundFromFile()
	{
		if(!buffer_button_click.loadFromFile(Config::button_click_sound_path))
			printf("Error loading background music file");
	}

	void SoundService::PlaySound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(buffer_button_click);
			break;
		default:
			printf("Invalid sound type");
			return;
		}

		sound_effect.play();
	}

	void SoundService::PlayBackgroundMusic()
	{
		background_music.setLoop(true);
		background_music.setVolume(background_music_volume);
		background_music.play();
	}
