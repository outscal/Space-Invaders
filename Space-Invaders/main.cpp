#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

//Player Class
class Player{

//Private Members
private:

    int playerScore = 10;
    int health = 100;
    int movementSpeed = 5;
    sf::Vector2f postion = sf::Vector2f(100,200);

//Public Members
public:
    sf::Texture texture;
    sf::Sprite sprite;
    Player()
    {
        
        
    }

    //Get Score
    int getScore()
    {
        return playerScore;
    }


    //Set Score
    void setScore(int newScore)
    {
        playerScore = newScore;
    }

    void TakeDamage()
    {

    }

    void ShootBulllets()
    {

    }

    void Movement()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            cout << "Left Key is pressed";
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            cout << "Right Key is pressed";
        }
    }



    sf::Vector2f getPosition()
    {
        return postion;
    }

    void  SetPosition(sf::Vector2f newPosition)
    {
        postion = newPosition;
    }


      

   

};




int main()
{   
    //Define Video Dimension
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    //Creating Window
    sf::RenderWindow window(videoMode, "Space Inavder");

    //Object of Player
    Player playerObj;

    //Loading texture
    playerObj.texture.loadFromFile("assets/textures/player_ship.png");
    playerObj.sprite.setTexture(playerObj.texture);

    //setting and getting player position
    playerObj.SetPosition(sf::Vector2f(400, 300));
    playerObj.sprite.setPosition(playerObj.getPosition());


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        //Player Ship Movement
        playerObj.Movement();

        //Clear Window and set color
        window.clear(sf::Color::Blue);

        //Draw Player Ship
        window.draw(playerObj.sprite);

        //Render to the screen
        window.display();
       
    }

  
    

 
    return 0;
}