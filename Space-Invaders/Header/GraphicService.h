#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class GraphicService {
public:
    const std::string game_window_title;
    const int game_window_width = 800;
    const int game_window_height = 600;
    const sf::Color window_color = sf::Color::Blue;

    sf::VideoMode* video_mode;
    sf::RenderWindow* game_window;

    GraphicService();
    ~GraphicService();

    void initialize();
    void update();
    void render();
    bool isGameWindowOpen();
    void initializeVariables();
    

    sf::RenderWindow* getGameWindow();
    sf::Color getWindowColor();
    sf::RenderWindow* createGameWindow();

private:
    
    void setVideoMode();
    void onDestroy();
    
};
