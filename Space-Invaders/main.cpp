#include<iostream>
#include<SFML/Graphics.hpp>

class Player {

    // Player properties
   //Private Access Modifiers
     int player_score = 0;
     sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
     int health = 3;
   
public: //Public Access Modifier
     sf::Texture player_texture;
     sf::Sprite player_sprite;
     int movement_speed = 5;
    
     //Public Getter & Setter methods
     int getScore() {
         return player_score;
     };

     void setScore(int newScore) {
         player_score = newScore;
     };




     //New methods
     void takeDamage() {};
     void move() {};
     void shootBullets() {};

};




int main()
{
    // A Player Object
    Player player;

    player.player_texture.loadFromFile("assets/textures/player_ship.png");

    player.player_sprite.setTexture(player.player_texture);
    //Difining the video mode dimensions
    sf::VideoMode videoMode = sf::VideoMode(800, 600);
    
    // creating a window object with specific dimensions and a title
    sf::RenderWindow window(videoMode, " SFML Window ");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)

                window.close();
        }



        // Handle  input

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

            // call move() here after the player object is created     

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {


        }


        // Clear the  window
        window.clear(sf::Color::Blue);

        

       window.draw(player.player_sprite);

        // Display whatever you draw
        window.display();

    }





    return 0;
}