#pragma once
#include <SFML/Graphics.hpp>

class GraphicService
{
private:

	const std::string game_window_title = "Avnish Presents - Space Invasion";

	const int game_window_width = 800;
	const int game_window_height = 600;

	const sf::Color window_color = sf::Color::Blue;

	sf::VideoMode* video_mode; // ptr to video mode
	sf::RenderWindow* game_window; // ptr to a RenderWindow

	void SetVideoMode(); // Method for setting our video mode
	void onDestroy(); // method to run when window is deleted

public:
	GraphicService();
	~GraphicService(); //cleanup

	//method to create the game window. returns a pointer to an instance of the game window
	sf::RenderWindow* CreateGameWindow();


	void Initialize(); //lifecycle functions
	void Update(); //..
	void Render(); //..
	bool IsGameWindowOpen(); //check if the window is open

	sf::RenderWindow* GetGameWindow(); //getter for the game window instance
	sf::Color GetWindowColor() const;//get the color
};