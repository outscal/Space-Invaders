#include "D:\Outscal\Space-Invaders\Space-Invaders\Header\Graphic\GraphicService.h"


GraphicService::GraphicService()
{
	videoMode = nullptr;
	gameWindow = nullptr;
}

GraphicService::~GraphicService()
{
	onDestroy();
}

void GraphicService::Initialize()
{
	gameWindow = CreateGameWindow();
	gameWindow->setFramerateLimit(frameRate);


}

sf::RenderWindow* GraphicService::CreateGameWindow()
{
	setVideoMode();
	return new sf::RenderWindow(*videoMode, gameWindowTitle);

}

void GraphicService::setVideoMode()
{
	videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel); // Allocates and sets the video mode
}

void GraphicService::onDestroy()
{
	delete(videoMode);
	delete(gameWindow);
	
}




void GraphicService::Update()
{
}

void GraphicService::Render()
{
}

bool GraphicService::isGameWindowOpen()
{
	return gameWindow->isOpen();
}

sf::RenderWindow* GraphicService::GetGameWindow()
{
	return gameWindow;
}

sf::Color GraphicService::getWindowColor()
{
	return windowColor;
}
