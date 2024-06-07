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
		//Decalring Variables
		const string game_window_title = "Space Invader";
		const int game_window_width = 800;
		const int game_window_height = 600;
		const sf::Color window_color = sf::Color::Blue;
		const int frame_rate = 60;

		//Decalring Pointer
		sf::VideoMode* video_mode;
		sf::RenderWindow* game_window;


		void setVideoMode();
		void destroyVideoMode();
	};
}

