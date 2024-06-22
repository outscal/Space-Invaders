#include <iostream>
#include "../../Header/Graphic/GraphicService.h"

using namespace std;

namespace Graphic
{
	GraphicService::GraphicService()
	{
		video_mode = nullptr;
		game_window = nullptr;
	}

	GraphicService::~GraphicService()
	{
		destroyVideoMode();
	}

	sf::RenderWindow* GraphicService::createGameWindow()
	{
		setVideoMode();
		return new sf::RenderWindow(*video_mode, game_window_title,sf::Style::Fullscreen);
	}

	void GraphicService::initialize()
	{
		game_window = createGameWindow();
		game_window->setFramerateLimit(frame_rate);
	}

	void GraphicService::update()
	{
	}

	void GraphicService::render()
	{
	}


	sf::RenderWindow* GraphicService::getGameWindow()
	{
		return game_window;
	}

	sf::Color GraphicService::gameWindowColor()
	{
		return window_color;

	}
	bool GraphicService::isGameWindowOpen()
	{
		return game_window->isOpen();
	}


	void GraphicService::setVideoMode()
	{
		video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
	}

	void GraphicService::destroyVideoMode()
	{
		delete(video_mode);
		delete(game_window);
	}

}
