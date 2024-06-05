<<<<<<< Updated upstream
#include <iostream>
#include "../Header/GraphicService.h"

using namespace std;

GraphicService::GraphicService()
{
    video_mode = nullptr;
    game_window = nullptr;
    cout << "GraphicService constructor called" << endl;
=======
#include "../Header/GraphicService.h"

GraphicService::GraphicService()
{
	video_mode = nullptr;
	game_window = nullptr;
>>>>>>> Stashed changes
}

GraphicService::~GraphicService()
{
<<<<<<< Updated upstream
    onDestroy();
    cout << "GraphicService destructor called" << endl;
}

void GraphicService::initialize()
{
    cout << "Initializing GraphicService" << endl;
    game_window = createGameWindow();
    if (game_window == nullptr) {
        cerr << "Failed to initialize game window" << endl;
    }
    else {
        cout << "Game window successfully created" << endl;
    }
=======
	destroyVideoMode();
>>>>>>> Stashed changes
}

sf::RenderWindow* GraphicService::createGameWindow()
{
<<<<<<< Updated upstream
    setVideoMode();
    if (video_mode != nullptr) {
        sf::RenderWindow* window = new sf::RenderWindow(*video_mode, game_title);
        if (window->isOpen()) {
            cout << "Render window is open" << endl;
        }
        else {
            cerr << "Render window failed to open" << endl;
        }
        return window;
    }
    cerr << "Failed to create game window: video_mode is null" << endl;
    return nullptr;
=======
	setVideoMode();
	return new sf::RenderWindow(*video_mode, game_window_title);
}

void GraphicService::initialize()
{
	game_window = createGameWindow();
}

void GraphicService::update()
{
}

void GraphicService::render()
{
}

bool GraphicService::isGameWindowOpen()
{
	return game_window->isOpen();
}

sf::RenderWindow* GraphicService::getGameWindow()
{
	return game_window;
}

sf::Color GraphicService::gameWindowColor()
{
	return window_color;
>>>>>>> Stashed changes
}

void GraphicService::setVideoMode()
{
<<<<<<< Updated upstream
    video_mode = new sf::VideoMode(game_width, game_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
    cout << "Video mode set: " << game_width << "x" << game_height << endl;
}

void GraphicService::update() {}
void GraphicService::render() {}

bool GraphicService::iSWindowOpen() 
{
    if (game_window != nullptr) {
        return game_window->isOpen();
    }
    cerr << "Attempt to check if window is open, but game_window is null" << endl;
    return false;
}

sf::RenderWindow* GraphicService::getGameWindow() 
{
    return game_window;
}

sf::Color GraphicService::getWindowColor() 
{
    return window_color;
}

void GraphicService::onDestroy()
{
    if (game_window != nullptr) {
        delete game_window;
        game_window = nullptr;
    }
    if (video_mode != nullptr) {
        delete video_mode;
        video_mode = nullptr;
    }
=======
	video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
}

void GraphicService::destroyVideoMode()
{
	delete(video_mode);
	delete(game_window);
>>>>>>> Stashed changes
}
