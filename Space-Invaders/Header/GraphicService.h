<<<<<<< Updated upstream
#include <SFML/Graphics.hpp>

class GraphicService {
public:
    GraphicService();
    ~GraphicService();

    void initialize();
    void update();
    void render();
    bool iSWindowOpen() ;
    sf::RenderWindow* getGameWindow() ;
    sf::Color getWindowColor() ;
  


private:
 
    sf::RenderWindow* createGameWindow();
    void setVideoMode();
    void onDestroy();

    sf::VideoMode* video_mode;
    sf::RenderWindow* game_window;
    const int game_width = 800;
    const int game_height = 600;
    const std::string game_title ="Space Inavder";
    const sf::Color window_color = sf::Color::Blue;
};

=======
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

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
	const string game_window_title = "Space Invadder";
	const int game_window_width = 800;
	const int game_window_height = 600;
	const sf::Color window_color =  sf::Color::Blue;

	//Decalring Pointer
	sf::VideoMode* video_mode;
	sf::RenderWindow* game_window;


	void setVideoMode();
	void destroyVideoMode();
};
>>>>>>> Stashed changes
