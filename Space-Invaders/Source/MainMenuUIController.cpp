#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Event\EventService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Time\TimeService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\MainMenu\MainMenuUIController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Main\GameService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\Config.h"
namespace UI
{
	namespace MainMenu
	{
		
		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace Event;
		using namespace Sound;

		MainMenuUIController::MainMenuUIController() { game_window = nullptr; }
		
		void MainMenuUIController::Initialize()
		{
			game_window = Global::ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			InitializeBackgroundImage();
			InitializeButtons();
		}
		void MainMenuUIController::InitializeBackgroundImage()
		{
			if (background_texture.loadFromFile(Config::background_texture_path))
			{
				background_sprite.setTexture(background_texture);
				ScaleBackgroundImage();
			}
		}
		void MainMenuUIController::ScaleBackgroundImage()
		{
			background_sprite.setScale(
				static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
				static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y);
		}
		void MainMenuUIController::InitializeButtons()
		{
			if (LoadButtonTexturesFromFile())
			{
				SetButtonSprites();
				ScaleAllButtons();
				PositionButtons();
			}
		}
		// only returns true if all tectures are loaded
		bool MainMenuUIController::LoadButtonTexturesFromFile()
		{
			return play_button_texture.loadFromFile(Config::play_button_texture_path) &&
				instructions_button_texture.loadFromFile(Config::instructions_button_texture_path) &&
				quit_button_texture.loadFromFile(Config::quit_button_texture_path);
		}
		void MainMenuUIController::SetButtonSprites()
		{
			play_button_sprite.setTexture(play_button_texture);
			instructions_button_sprite.setTexture(instructions_button_texture);
			quit_button_sprite.setTexture(quit_button_texture);
		}
		void MainMenuUIController::ScaleAllButtons()
		{
			ScaleSpecificButton(&play_button_sprite);
			ScaleSpecificButton(&instructions_button_sprite);
			ScaleSpecificButton(&quit_button_sprite);
		}
		void MainMenuUIController::ScaleSpecificButton(sf::Sprite* button_to_scale)
		{
			button_to_scale->setScale(
				button_width / button_to_scale->getTexture()->getSize().x,
				button_height / button_to_scale->getTexture()->getSize().y);
		}
		void MainMenuUIController::PositionButtons()
		{
			float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
			play_button_sprite.setPosition({ x_position, 500.f });
			instructions_button_sprite.setPosition({ x_position, 700.f });
			quit_button_sprite.setPosition({ x_position, 900.f });
		}
		void MainMenuUIController::ProcessButtonInteractions()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

			if (ClickedButton(&play_button_sprite, mouse_position))
			{	
				ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK); //play button sound
				ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic(); //play background music
				GameService::SetGameState(GameState::GAMEPLAY);
			}
			if (ClickedButton(&instructions_button_sprite, mouse_position))
			{	
				ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK); //play button sound
				printf("Clicked Instructions Button!\\n");
			}
			if (ClickedButton(&quit_button_sprite, mouse_position))
			{
				ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK); //play button sound
				game_window->close();
			}
		}
		bool MainMenuUIController::ClickedButton(sf::Sprite* button_sprite,sf::Vector2f mouse_position)
		{
			EventService* event_service = Global::ServiceLocator::GetInstance()->GetEventService();
			return event_service->PressedLMB() && button_sprite->getGlobalBounds().contains(mouse_position);
		}
		void MainMenuUIController::Update()
		{
			ProcessButtonInteractions();
		}
		void MainMenuUIController::Render()
		{
			game_window->draw(background_sprite);
			game_window->draw(play_button_sprite);
			game_window->draw(instructions_button_sprite);
			game_window->draw(quit_button_sprite);
		}
	}
}