#include "../../Header/UIService/MainMenuUIController/MainMenuUIController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Main/GameService.h";

#include "../../Header/Event/EventService.h"


namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Event;
		using namespace Graphic;
		using namespace Main;

		MainMenuUIController::MainMenuUIController()
		{
			game_window = nullptr;
		}

		void MainMenuUIController::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeBackground();
			initializeButton();

		}
		void MainMenuUIController::update()
		{
			processButtonInput();
		}
		void MainMenuUIController::render()
		{
			cout << "Render";
			game_window->draw(background_sprite);
			game_window->draw(play_button_sprite);
			game_window->draw(instruction_button_sprite);
			game_window->draw(quit_button_sprite);
		}
		void MainMenuUIController::initializeBackground()
		{
			if (background_texture.loadFromFile(background_texture_path))
			{
				cout << "Background loaded" <<endl;
				background_sprite.setTexture(background_texture);
				setBackgroundScale();
			}
		}
		void MainMenuUIController::setBackgroundScale()
		{
			background_sprite.setScale(
				static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
				static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y);
		}
		void MainMenuUIController::initializeButton()
		{
			if (loadFromTexture())
			{
				cout << "Button loaded" << endl;

				setButtonSprite();
				scaleAllButton();
				positionButton();
			}
			
		}
		bool MainMenuUIController::loadFromTexture()
		{
			return play_button_texture.loadFromFile(play_button_path) && instruction_button_texture.loadFromFile(instruction_button_path) && quit_button_texture.loadFromFile(quit_button_path);
		}
		void MainMenuUIController::setButtonSprite()
		{
			play_button_sprite.setTexture(play_button_texture);
			instruction_button_sprite.setTexture(instruction_button_texture);
			quit_button_sprite.setTexture(quit_button_texture);

		}
		void MainMenuUIController::scaleAllButton()
		{
			setButtonScale(&play_button_sprite);
			setButtonScale(&instruction_button_sprite);
			setButtonScale(&quit_button_sprite);
		}
		void MainMenuUIController::setButtonScale(sf::Sprite* button_to_scale)
		{
			button_to_scale->setScale(
				button_width / button_to_scale->getTexture()->getSize().x,
				button_height / button_to_scale->getTexture()->getSize().y
			);
		}
		void MainMenuUIController::positionButton()
		{
			float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

			play_button_sprite.setPosition(sf::Vector2f(x_position, 500.f));
			instruction_button_sprite.setPosition(sf::Vector2f(x_position, 700.f));
			quit_button_sprite.setPosition(sf::Vector2f(x_position, 900));

		}

		void MainMenuUIController::processButtonInput()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));
			if (buttonClick(&play_button_sprite, mouse_position))
			{
				GameService::setGameState(GameState::GAMEPLAY);
			}
			if (buttonClick(&instruction_button_sprite, mouse_position))
			{
				printf("Instruction Button Clicked \\n");
			}
			if (buttonClick(&quit_button_sprite, mouse_position))
			{
				game_window->close();
			}
			
		}

		bool MainMenuUIController::buttonClick(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
		{
			Event::EventService* event_service = ServiceLocator::getInstance()->getEventService();
			return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
		}



	}

}

