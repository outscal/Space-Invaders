#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>

// namespace sf {
    

  //  class VideoMode {

    //   public:

    //    VideoMode(int width, int height) {

    //    }

   // };
 //   class RenderWindow {

 //   public:

  //      RenderWindow(VideoMode videoMode, const char* name) {

  //      }
 //   };
//}
//void gameloop() {
    
//}



int main() {

// Define the video mode (dimensions)
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    sf::RenderWindow window(videoMode, "SFML Window");
  //  gameloop();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }
        }
    window.setFramerateLimit(60);


        window.clear(sf::Color::Blue);

       
        window.display();


    return 0;
}