//#include "../Header/circle.h"
//#include "../Header/ServiceLocator.h"
//
//circledraw::circledraw()
//{
//	game_window = nullptr;
//}
//
//circledraw::~circledraw() = default;
//
//void circledraw::drawcircle() 
//{
//		sf::CircleShape circle(50); // Radius 50
//	circle.setFillColor(sf::Color::Red);
//	circle.setPosition(400, 300); // Set position
//}
//
//void circledraw::initialize()
//{
//	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
//	//initializePlayerSprite();
//	drawcircle();
//}
//
////take our players input in update, then set the position.
////order is important here
//void circledraw::update()
//{
//	//processPlayerInput();
//	//player_sprite.setPosition(getPlayerPosition());
//}
//
//void circledraw::render()
//{
//	game_window->draw(circlepart);
//}
//
