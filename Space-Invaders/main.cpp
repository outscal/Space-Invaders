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

   
     //// Public Getter & Setter methods
   //  int getScore() {
   //      return player_score;
   //  }
  
   //  void setScore(int newScoer) {
   //  
   //      player_score = newScoer;
   //  
   //  }


     //New methods
     void takeDamage() {};
     void move() {};
     void shootBullets() {};

     

};





int main()
{
    // A Player Object
    Player player;

    //// Accessing the private variables using the public getter
    //std::cout << " Players Score " << player.getScore() << "\n";
    //
    //// Modifying the variables using the public setter
    //player.setScore(100);

    ////Acessing the modified variable using the public getter
    //std::cout << " Player Modified scosre. " << player.getScore() << "\n";


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

        // Clear the  window
        window.clear(sf::Color::Blue);

        // Display whatever you draw
        window.display();









    }


    





    return 0;
}