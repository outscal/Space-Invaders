//#include "../Header/PlayerService.h"
//#include "../Header/ServiceLocator.h"
//
//PlayerService::PlayerService()
//{
//	game_window = nullptr;
//}
//
//PlayerService::~PlayerService() = default;
//
////init
//void PlayerService::initialize()
//{
//	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
//	initializePlayerSprite();
//}
//
////take our players input in update, then set the position.
////order is important here
//void PlayerService::update()
//{
//	processPlayerInput();
//	player_sprite.setPosition(getPlayerPosition());
//}
//
//void PlayerService::render()
//{
//	game_window->draw(player_sprite);
//}
//
////void PlayerService::processPlayerInput()
////{
////	// Handle keyboard input
////	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
////		move(-1.0f * getMoveSpeed());
////	}
////	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
////		move(1.0f * getMoveSpeed());
////	}
////}
//
////changed Player Input
//void PlayerService::processPlayerInput()
//{
//	EventService* event_service = ServiceLocator::getInstance()->getEventService();
//
//	if (event_service->isKeyboardEvent()) //check if a key has been pressed
//	{
//		if (event_service->pressedLeftKey())
//		{
//			moveLeft();
//		}
//
//		if (event_service->pressedRightKey())
//		{
//			moveRight();
//		}
//	}
//}
//
//// New movement methods
//void PlayerService::moveLeft()
//{
//	position.x -= movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
//}
//
//void PlayerService::moveRight()
//{
//	position.x += movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
//}
//
//void PlayerService::initializePlayerSprite()
//{
//	if (player_texture.loadFromFile(player_texture_path))
//	{
//		player_sprite.setTexture(player_texture);
//	}
//}
//
//void PlayerService::move(float offsetX) {
//	position.x += offsetX*ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
//}
//
////helper functions
//sf::Vector2f PlayerService::getPlayerPosition() { return position; }
//int PlayerService::getMoveSpeed() { return movement_speed; }
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Player/PlayerController.h"

PlayerService::PlayerService()
{
	player_controller = new PlayerController();
}

PlayerService::~PlayerService()
{
	delete (player_controller);
}

void PlayerService::initialize()
{
	player_controller->initialize();
}

void PlayerService::update()
{
	player_controller->update();
}

void PlayerService::render()
{
	player_controller->render();
}