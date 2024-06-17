#include <iostream>
#include <SFML/Graphics.hpp>

//Creating empty player class below
class Player {
    private: // private access modifier
        //private properties
        int health = 3;
        sf::Vector2f position = sf::Vector2f(200.0f, 100.0f);
        int movement_speed = 5;
        int player_score = 0;

    public: // public access modifier 
        //public Properties
        sf::Texture player_texture;
        sf::Sprite player_sprite; 

    //Public Getter & Setter methods
        int getScore() {
            return player_score;
        }
        void setScore(int newScore) {
            player_score = newScore;
        }
        void takeDamage() {};
        void move() {};
        void shootBullets() {}
};

int main()
{
    //Creating player object
    Player player;

    //Access the private variable using the public getter
    std::cout << "Player Score:" << player.getScore() << "\\n";
    //Modify the variable using the public setter
    player.setScore(100);
    //Access the modified variable using the public getter
    std::cout << "Player Modified Score:" << player.getScore() << "\\n";
}  
