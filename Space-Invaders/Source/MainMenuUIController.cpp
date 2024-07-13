#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\MainMenu\MainMenuUIController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Main\GameService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\Config.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Sound\SoundService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Event\EventService.h"


namespace UI
{
	namespace MainMenu
	{
		
		using namespace Global;
		using namespace Main;
		using namespace UIElement;
		using namespace Sound;

		MainMenuUIController::MainMenuUIController() 
		{ 
			CreateImage();
			CreateButtons();
		}
		MainMenuUIController::~MainMenuUIController()
		{
			Destroy();
		}
		
		void MainMenuUIController::Initialize()
		{
			RegisterButtonCallback();
			InitializeBackgroundImage();
			InitializeButtons();
		}
		void MainMenuUIController::CreateImage()
		{
			background_image = new ImageView();
		}
		void MainMenuUIController::CreateButtons()
		{
			play_button = new ButtonView();
			instructions_button = new ButtonView();
			quit_button = new ButtonView();
		}
		void MainMenuUIController::InitializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			background_image->Initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->SetImageAlpha(background_alpha);
		}
		void MainMenuUIController::InitializeButtons()
		{
			play_button->Initialize("Play Button", Config::play_button_texture_path, button_width, button_height, sf::Vector2f(0, play_button_y_position));
			instructions_button->Initialize("Instructions Button", Config::instructions_button_texture_path, button_width, button_height, sf::Vector2f(0, instructions_button_y_position));
			quit_button->Initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(0, quit_button_y_position));

			play_button->SetCentreAlinged();
			instructions_button->SetCentreAlinged();
			quit_button->SetCentreAlinged();
		}
		void MainMenuUIController::RegisterButtonCallback()
		{
			play_button->RegisterCallbackFuntion(std::bind(&MainMenuUIController::PlayButtonCallback, this));
			instructions_button->RegisterCallbackFuntion(std::bind(&MainMenuUIController::InstructionsButtonCallback, this));
			quit_button->RegisterCallbackFuntion(std::bind(&MainMenuUIController::QuitButtonCallback, this));
		}

		void MainMenuUIController::PlayButtonCallback()
		{
			ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
			GameService::SetGameState(GameState::GAMEPLAY);
		}

		void MainMenuUIController::InstructionsButtonCallback()
		{
			ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
		}

		void MainMenuUIController::QuitButtonCallback()
		{
			ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->close();
		}
		void MainMenuUIController::Update()
		{
			background_image->Update();
			play_button->Update();
			instructions_button->Update();
			quit_button->Update();
		}

		void MainMenuUIController::Render()
		{
			background_image->Render();
			play_button->Render();
			instructions_button->Render();
			quit_button->Render();
		}

		void MainMenuUIController::Show()
		{
			background_image->Show();
			play_button->Show();
			instructions_button->Show();
			quit_button->Show();

			ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
		}
		void MainMenuUIController::Destroy()
		{
			delete (play_button);
			delete (instructions_button);
			delete (quit_button);
			delete (background_image);
		}
	}
}