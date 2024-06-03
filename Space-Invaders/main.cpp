#include<iostream>
#include "Header/GameService.h"
#include<SFML/Graphics.hpp>

//class Player {
//private:
//    // Player properties
//     int player_score = 0;
//     sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
//     int health = 3;
//   
//public: //Public Access Modifier
//     sf::Texture player_texture;
//     sf::Sprite player_sprite;
//     int movement_speed = 5;
//   
//     //New methods
//     void takeDamage() {};
//     void move(float offsetX) {
//         position.x += offsetX;
//     }
//     int getMoveSpeed() {
//         return movement_speed;
//     }
//     sf::Vector2f getPosition() {
//         return position;
//     }
//     void shootBullets() {};
//
//};

//int main()
//{
//   //Difining the video mode dimensions
//    sf::VideoMode videoMode = sf::VideoMode(800, 600);
//    
//    // creating a window object with specific dimensions and a title
//    sf::RenderWindow window(videoMode, " SFML Window ");
//
//    // A Player Object
//    Player player;
//
//    //Loading player ship texture
//    player.player_texture.loadFromFile("assets/textures/player_ship.png");
//    //setintg the player ship texture
//    player.player_sprite.setTexture(player.player_texture);
//
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//
//                window.close();
//        }
//
//        // Handle  inpu
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//            player.move(-1.0f * player.getMoveSpeed());
//        }
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//           player.move(1.0f * player.getMoveSpeed());
//        }
//
//        // Clear the  window
//        window.clear(sf::Color::Blue);
//        
//        //setting the the player sptite position
//        player.player_sprite.setPosition(player.getPosition());
//        
//        //Draw the player sprite
//       window.draw(player.player_sprite);
//
//        // Display whatever you draw
//        window.display();
//    }
//    return 0;
//}

int main()
{
	GameService game_service; // created an object
	game_service.ignite();  // this will start the flow of our game

	// game loop
	while(game_service.isRunning())
	{
	
		game_service.ignite();
		game_service.render();
	
	}

	return 0;
}