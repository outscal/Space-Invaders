#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>

namespace Graphic
{
	class GraphicService {

	private:

		const string gameWindowTitle = "SPACE INVADERS";

		const int gameWindowHeight = 1920;
		const int gameWindowWidth = 1080;
		const int frameRate = 60;

		const sf::Color gameWindowColor = sf::Color::Blue;

		sf::VideoMode* videoMode{ nullptr }; // ptr to video mode
		sf::RenderWindow* gameWindow{ nullptr }; //pointer to renderwindow : we have created an object using pointers to manually delete the said object and pointer. 

		void SetVideoMode();  // Method for setting our video mode;

		void OnDestroy(); // method to run when window is delete};


	public:
		GraphicService();
		~GraphicService();
		sf::RenderWindow* CreateGameWindow(); //method to create the game window. returns a pointer to an instance of the game window

		void initialize(); //lifecycle functions
		void update();
		void render();
		bool isGameWindowOpen() const;//check if the window is open

		sf::RenderWindow* GetGameWindow() const;//getter for the game window instance
		sf::Color GetWindowColor() const;//get the color

	};
}

