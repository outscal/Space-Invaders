#include <iostream>
#include "../../HeaderFiles/Graphic/GraphicService.h"
#include <SFML/Graphics.hpp>
using namespace std;

namespace Graphic {
	//Constructor
	GraphicService::GraphicService() {
		gameWindow = nullptr; // Initializes game window pointer to null
		videoMode = nullptr;  // Initializes video mode pointer to null
	}
	GraphicService::~GraphicService() {
		OnDestroy(); // Calls onDestroy method to clean up resources
	}
	void GraphicService::initialize() {
		gameWindow = CreateGameWindow(); // Assigns a new game window to the game_window pointer
		gameWindow->setFramerateLimit(frameRate);
	}
	void GraphicService::OnDestroy() {
		delete videoMode; // Deletes the video mode object
		delete gameWindow; // Deletes the game window object

	}
	sf::RenderWindow* GraphicService::CreateGameWindow() {
		SetVideoMode();
		return new sf::RenderWindow(*videoMode, gameWindowTitle,sf::Style::Fullscreen);
	}
	// Sets up the video mode for the game window using specified dimensions and system's color depth.
	void GraphicService::SetVideoMode() {
		videoMode = new sf::VideoMode(gameWindowHeight, gameWindowWidth, sf::VideoMode::getDesktopMode().bitsPerPixel); // Allocates and sets the video mode
	}
	sf::RenderWindow* GraphicService::GetGameWindow() const {
		return gameWindow;
	}
	sf::Color GraphicService::GetWindowColor() const {
		return gameWindowColor;
	}

	void GraphicService::update() {

	}
	void GraphicService::render() {

	}
	bool GraphicService::isGameWindowOpen() const {

		return gameWindow->isOpen();
	}
}
