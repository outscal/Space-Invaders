#pragma once
#include <SFML/Graphics.hpp>
//#include "../../Header/Player/PlayerController.h"

class PlayerController;
class PlayerModel;

class PlayerView
{
private:

    const sf::String player_texture_path = "assets/textures/player_ship.png";
    const float player_sprite_width = 60.f;
    const float player_sprite_height = 60.f;

    sf::RenderWindow* game_window;

  PlayerController* player_controller; // ptr to player controller

    sf::Texture player_texture;
    sf::Sprite player_sprite;

    void initializePlayerSprite();
    void scalePlayerSprite();

public:
    PlayerView();
    ~PlayerView();

    void initialize(PlayerController* controller); // we pass a pointer of type controller because we need to use this in the view later.
   // void initialize();
    void update();
    void render();

   
};
