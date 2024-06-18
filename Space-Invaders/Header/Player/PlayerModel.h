#pragma once
#include <SFML/Graphics.hpp>


enum class PlayerState //Our Enum
{
    ALIVE,
    DEAD,
    // we will add more states later
};



class PlayerModel
{
private:

    const sf::Vector2f initial_player_position = sf::Vector2f(950.f, 950.f); //new var
    sf::Vector2f player_position; //new var
    
    PlayerState player_state;

public:

    const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
    const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);

    const float player_movement_speed = 350.0f;

    PlayerModel();
    ~PlayerModel();

    void initialize();

    void reset(); //new method


    //getters and setters
    sf::Vector2f getPlayerPosition();
    void setPlayerPosition(sf::Vector2f position);

    //new getter and setter
    PlayerState getPlayerState();
    void setPlayerState(PlayerState state);

};