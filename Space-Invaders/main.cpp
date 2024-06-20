
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>

class Player {

private:
    int playerScore = 0;
    int health = 1;
    int movementSpeed = 10;


public:
    sf::Texture playershiptexture;
    sf::Sprite playershipsprite;

    int getScore()
    {
        return playerScore;
      }
    void setScore(int newScore) {
        playerScore = newScore;
    }

    void takeDamage() {

        cout << "Player took damage" << endl;
    };

    void move() {
       cout<<"Player is moving" << endl;
    };

    void shootBullets() {
        cout << "Player is shooting bullets" << endl;
    };

   
};

int main()
{
    //render a blue colored window
    sf::VideoMode videomode = sf::VideoMode(800, 600);
    sf::RenderWindow window(videomode, "SFML Window");
    Player player;

    sf::Texture playership;
    playership.loadFromFile("assets/textures/player_ship.png");
    sf::Sprite playershipsprite;
    playershipsprite.setTexture(playership);                                // sprite.setTexture(texture);
    // set position, rotation, scale and more

    playershipsprite.setPosition(300, 450);
    playershipsprite.setRotation(0);
    playershipsprite.setScale(1, 1); 
    cout << "Player score is " << player.getScore() << endl;;
    player.setScore(100);
    cout <<"New player score: "<<player.getScore() << endl;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Check for window closure
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {

                player.move();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {

                player.move();
            }


            //Clear the window
            window.clear(sf::Color::Blue);
            //Draw assets
            window.draw(playershipsprite);
            //Display window to display whatever drawn
            window.display();
        }


    }

    return 0;
}