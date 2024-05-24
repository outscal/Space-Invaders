#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include <iostream>

// Constructor: Initializes game window and video mode pointers to null.
GraphicService::GraphicService() {
    game_window = nullptr;
    video_mode = nullptr;
}

// Destructor: Cleans up resources by calling onDestroy.
GraphicService::~GraphicService() {
    onDestroy();
}

// Initializes the graphic service by creating a new game window.
void GraphicService::Initialize() {
    game_window = CreateGameWindow();
}

// Creates a new SFML RenderWindow object with specified video mode and title.
sf::RenderWindow* GraphicService::CreateGameWindow() {
    SetVideoMode(); // Sets up the video mode for the window
    game_window = new sf::RenderWindow(*video_mode, game_window_title);
    if (game_window->isOpen()) {
        std::cout << "Game window is successfully open\n";
        return game_window;
    }
    else
    {
        std::cout << "Error : Game window closed returning null value.\n";
        return nullptr;
    }
}

// Sets up the video mode for the game window using specified dimensions and system's color depth.
void GraphicService::SetVideoMode() {
    video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
}

// Cleans up allocated memory for video mode and game window to avoid memory leaks.
void GraphicService::onDestroy() 
{
    delete video_mode;
    video_mode = nullptr;
    delete game_window;
    game_window = nullptr;
}

// Placeholder function for game update logic.
void GraphicService::Update() {}

// Placeholder function for game rendering logic.
void GraphicService::Render() {}

// Checks if the game window is currently open.
bool GraphicService::IsGameWindowOpen() { return game_window && game_window->isOpen(); }

// Returns a pointer to the game window object.
sf::RenderWindow* GraphicService::GetGameWindow() {return game_window;}

// Returns the configured window background color.
sf::Color GraphicService::GetWindowColor() const {return window_color;}