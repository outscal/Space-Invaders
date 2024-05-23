#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\GraphicService.h"

GraphicService::GraphicService()
{
	game_window = nullptr;
	video_mode = nullptr;
}
GraphicService::~GraphicService() { onDestroy();}
// Initializes the graphic service by creating a new game window.
void GraphicService::Initialize()
{
	game_window = CreateGameWindow();
}
// Creates a new SFML RenderWindow object with specified video mode and title.
sf::RenderWindow* GraphicService::CreateGameWindow()
{
	SetVideoMode();
	return new sf::RenderWindow(*video_mode, game_window_title);
}
// Sets up the video mode for the game window using specified dimensions and system's color depth.
void GraphicService::SetVideoMode()
{
	video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel); // Allocates and sets the video mode
}
// Cleans up allocated memory for video mode and game window to avoid memory leaks.
void GraphicService::onDestroy() {
	delete(video_mode); // Deletes the video mode object
	delete(game_window); // Deletes the game window object
}
// Function for game update logic.
void GraphicService::Update() { }

// Function for game rendering logic.
void GraphicService::Render() { }

// Checks if the game window is currently open.
bool GraphicService::IsGameWindowOpen() { return game_window->isOpen(); } // Returns Open

// Returns a pointer to the game window object.
sf::RenderWindow* GraphicService::GetGameWindow() {return game_window;}

// Returns the configured window background color.
sf::Color GraphicService::GetWindowColor() { return window_color; }
