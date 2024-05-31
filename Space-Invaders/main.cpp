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
        cout << "Default Constuctor" <<"\n";
    }

    Player(int intialHealth, int movement_Speed)
    {
        health = intialHealth;
        movementSpeed = movement_Speed;

        cout << "New Health: " << health <<"\n";
        cout << "New Movement Speed: " << movementSpeed<<"\n";
    }

    //Destructor
    ~Player()
    {
        cout << "Player is Destroyed and resouces are free" << "\n";
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

    void Movement(float offsetX)
    {
        postion.x += offsetX;
    }



    sf::Vector2f getPosition()
    {
        return postion;
    }

    int getmovementSpeed()
    {
        return movementSpeed;
    }


      

   

};




int main()
{   
    //Define Video Dimension
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    //Creating Window
    sf::RenderWindow window(videoMode, "Space Inavder");

    //Object of Player
    Player playerObj1;
    Player playerObj2(50,2);

    //Loading texture
    playerObj1.texture.loadFromFile("assets/textures/player_ship.png");
    playerObj1.sprite.setTexture(playerObj1.texture);

   


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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            playerObj1.Movement(-1.0 * playerObj1.getmovementSpeed());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            playerObj1.Movement(1.0 * playerObj1.getmovementSpeed());
        }

        //Clear Window and set color
        window.clear(sf::Color::Blue);

        //Setting the position of Sprite
        playerObj1.sprite.setPosition(playerObj1.getPosition());

        //Draw Player Ship
        window.draw(playerObj1.sprite);

        //Render to the screen
        window.display();
       
    }

  
    

 
    return 0;
}