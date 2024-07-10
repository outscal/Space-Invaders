#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>




class GraphicService {

private:

	const string gamewindowtitle = "SPACE INVADERS";

	const int gamewindowheight = 800;
	const int gamewindowwidth = 600;

	const sf::Color gamewindowcolor = sf::Color::Blue;

	sf::VideoMode* videomode{ nullptr }; // ptr to video mode
	sf::RenderWindow* gamewindow{ nullptr }; //pointer to renderwindow : we have created an object using pointers to manually delete the said object and pointer. 

	void SetVideoMode();  // Method for setting our video mode;

	void OnDestroy(); // method to run when window is delete};


public:
	GraphicService();
	~GraphicService();
	sf::RenderWindow* CreateGameWindow(); //method to create the game window. returns a pointer to an instance of the game window

	void initialize(); //lifecycle functions
	void update(); //..
	void render(); //..
	bool isGameWindowOpen() const;//check if the window is open

	sf::RenderWindow* GetGameWindow() const;//getter for the game window instance
	sf::Color GetWindowColor() const;//get the color

};
