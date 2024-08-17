#pragma once
#include<SFML/Graphics.hpp>

class GraphicService
{
private:
	const std::string gameWindowTitle = "Space Invaders";


	const int gameWindowWidth = 800;
	const int gameWindowHeight = 600;

	const sf::Color windowColor = sf::Color::Blue;

	const int frameRate=60;

	sf::VideoMode* videoMode;
	sf::RenderWindow* gameWindow;
	void setVideoMode(); // Method for setting our video mode
	void onDestroy(); // method to run when window is deleted


public:

	GraphicService();
	~GraphicService();
	sf::RenderWindow* CreateGameWindow();


	void Initialize();
	void Update();
	void Render();
	bool isGameWindowOpen();


	sf::RenderWindow* GetGameWindow();
	sf::Color getWindowColor();

};