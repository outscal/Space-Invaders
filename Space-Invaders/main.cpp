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
    playerObj.setScore(20);
    cout << "Player Score : " << playerObj.getScore()<<"\n";


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
        //Clear Window and set color
        window.clear(sf::Color::Blue);

        //Render to the screen
        window.display();
       
    }

  
    

 
    return 0;
}