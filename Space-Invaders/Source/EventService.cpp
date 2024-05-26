#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Event\EventService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Main\GameService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
namespace Event
{
	using namespace Global;
	EventService::EventService()
	{
		game_window = nullptr;
		game_event.type = sf::Event::KeyPressed;
	}
	EventService::~EventService() = default;

	void EventService::Initialize()
	{
		game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
	}
	void EventService::Update()
	{

	}
	void EventService::ProcessEvents()
	{
		if (IsGameWindowOpen() == true)
		{
			while (game_window->pollEvent(game_event))
			{
				//Check for window closure
				if (GameWindowWasClosed() || HasQuitGame())
				{
					game_window->close();
				}

			}

		}
	}
	bool EventService::HasQuitGame() { return (IsKeyboardEvent() && PressedEscapeKey()); }

	bool EventService::IsKeyboardEvent() { if (game_event.type == sf::Event::KeyPressed) { return  true; } else return false; }

	bool EventService::PressedEscapeKey() { if (game_event.key.code == sf::Keyboard::Escape) { return true; } else return false; }

	bool EventService::IsGameWindowOpen() { return game_window != nullptr; }

	bool EventService::GameWindowWasClosed() { return game_event.type == sf::Event::Closed; }

	bool EventService::PressedLeftKey() { return game_event.key.code == sf::Keyboard::Left; }

	bool EventService::PressedRightKey() { return game_event.key.code == sf::Keyboard::Right; }
	
	bool EventService::PressedLMB()
	{
		return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Left;
	}
	bool EventService::PressedRMB()
	{
		return game_event.type == sf::Event::MouseButtonPressed && game_event.mouseButton.button == sf::Mouse::Right;
	}
}
