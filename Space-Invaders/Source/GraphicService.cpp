#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\GraphicService.h"
#include<iostream>
// Constructor: Initializes game window and video mode pointers to null.
GraphicService::GraphicService() {
	game_window = nullptr; // Initializes game window pointer to null
	video_mode = nullptr;
}

// Destructor: Cleans up resources by calling onDestroy.
GraphicService::~GraphicService() {
	onDestroy(); // Calls onDestroy method to clean up resources
}

// Initializes the graphic service by creating a new game window.
void GraphicService::Initialize() {
	game_window = CreateGameWindow(); // Assigns a new game window to the game_window pointer
}

// Creates a new SFML RenderWindow object with specified video mode and title.
sf::RenderWindow* GraphicService::CreateGameWindow() {
	SetVideoMode(); // Sets up the video mode for the window
	game_window = new sf::RenderWindow(*video_mode, game_window_title);
	if(game_window)
	return game_window; // Creates and returns a new RenderWindow object
}

// Sets up the video mode for the game window using specified dimensions and system's color depth.
void GraphicService::SetVideoMode() {
	video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel); // Allocates and sets the video mode
}

// Cleans up allocated memory for video mode and game window to avoid memory leaks.
void GraphicService::onDestroy() {
	delete(video_mode); // Deletes the video mode object
	video_mode = nullptr;
	delete(game_window); // Deletes the game window object
	game_window = nullptr;
}

// Placeholder function for game update logic.
void GraphicService::Update() { }

// Placeholder function for game rendering logic.
void GraphicService::Render() { }

// Checks if the game window is currently open.
bool GraphicService::IsGameWindowOpen() {
	return game_window&&game_window->isOpen(); // Returns the open status of the game window
}

// Returns a pointer to the game window object.
sf::RenderWindow* GraphicService::GetGameWindow() {
	return game_window;
}

// Returns the configured window background color.
sf::Color GraphicService::GetWindowColor() const {
	return window_color;
}