

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
#include <SFML/Graphics.hpp>



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

        // window.setFramerateLimit(60);
        window.display();

        window.clear(sf::Color::Blue);
    }

       
      


    return 0;
}