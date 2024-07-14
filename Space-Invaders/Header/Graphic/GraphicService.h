#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

namespace Graphic
{
	class GraphicService
	{
	public:
		GraphicService();
		~GraphicService();

		sf::RenderWindow* createGameWindow();

		void initialize();
		void update();
		void render();
		bool isGameWindowOpen();

		sf::RenderWindow* getGameWindow();
		sf::Color gameWindowColor();

	private:
		//Declaring Variables
		const string game_window_title = "Space Invader";
		const int game_window_width = 1920;
		const int game_window_height = 1080;
		const sf::Color window_color = sf::Color::Blue;
		const int frame_rate = 60;

		//Declaring Pointer
		sf::VideoMode* video_mode;
		sf::RenderWindow* game_window;


		void setVideoMode();
		void destroyVideoMode();
	};
}

