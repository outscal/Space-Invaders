#pragma once.
#include<SFML/Graphics.hpp>

class GraphicService
{
private:
	const std::string game_window_title = "Alien Invader";

	const int game_window_width = 800;
	const int game_window_height = 600;

	const sf::Color window_color = sf::Color::Red;
	sf::VideoMode* video_mode;
	sf::RenderWindow* game_window;

	void setVideoMode();
	void OnDestroy();

public:
	GraphicService();
	~GraphicService();
	//method to create the game window. returns a pointer to an instance of the game window
	sf::RenderWindow* createGameWindow();

	//lifecycle functions
	void initialize();
	void update();
	void render();
	bool isGameWindowOpen();

	sf::RenderWindow* getGameWindow();
	sf::Color getWindowColor();
};