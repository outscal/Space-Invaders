#include <iostream>
#include "../HeaderFiles/GraphicService.h"
#include <SFML/Graphics.hpp>
using namespace std;


//Constructor
GraphicService::GraphicService() {
	gamewindow = nullptr; // Initializes game window pointer to null
	videomode = nullptr;  // Initializes video mode pointer to null
}
GraphicService::~GraphicService() {
	OnDestroy(); // Calls onDestroy method to clean up resources
}
void GraphicService::initialize() {
	gamewindow = CreateGameWindow(); // Assigns a new game window to the game_window pointer
}
void GraphicService::OnDestroy() {
	delete videomode; // Deletes the video mode object
	delete gamewindow; // Deletes the game window object

}
sf::RenderWindow*GraphicService::CreateGameWindow() {
	SetVideoMode();
	return new sf::RenderWindow(*videomode, gamewindowtitle);
}
// Sets up the video mode for the game window using specified dimensions and system's color depth.
void GraphicService::SetVideoMode() {
	videomode = new sf::VideoMode(gamewindowheight,gamewindowwidth, sf::VideoMode::getDesktopMode().bitsPerPixel); // Allocates and sets the video mode
}
sf::RenderWindow* GraphicService::GetGameWindow() const {
	return gamewindow;
}
sf::Color GraphicService::GetWindowColor() const{
	return gamewindowcolor;
}

void GraphicService::update() {

}
void GraphicService::render() {

}
bool GraphicService::isGameWindowOpen() const{
	return gamewindow ->isOpen();
}
