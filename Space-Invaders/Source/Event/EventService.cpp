#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Event\EventService.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Main\GameService.h"
#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Graphic\GraphicService.h"


EventService::EventService()
{
    gameWindow = nullptr;
}

EventService::~EventService() = default;

void EventService::Initialize()
{
    gameWindow = ServiceLocator::GetInstance()->getGraphicService()->GetGameWindow();

}

void EventService::Update()
{


}

void EventService::ProcessEvents()
{
    if (isGameWindowOpen())
    {
        while (gameWindow->pollEvent(gameEvent))
        {
            if (gameWindowWasClosed() || hasQuitGame())
            {
                
                gameWindow->close();
            }
        }
    }


}

bool EventService::hasQuitGame()
{
    return (isKeyboardEvent() && PressedEscapeKey());
}

bool EventService::isKeyboardEvent()
{
    return gameEvent.type ==  sf::Event::KeyPressed;
}

bool EventService::PressedEscapeKey()
{
    return gameEvent.key.code == sf::Keyboard::Escape;
}

bool EventService::isGameWindowOpen()
{
    return gameWindow != nullptr;
}

bool EventService::gameWindowWasClosed()
{
    return gameEvent.type == sf::Event::Closed;

}

bool EventService::pressedLeftKey()
{
    return gameEvent.key.code == sf::Keyboard::Left;
}

bool EventService::pressedRightKey()
{
    return gameEvent.key.code == sf::Keyboard::Right;
}












