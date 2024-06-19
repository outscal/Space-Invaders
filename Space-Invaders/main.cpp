

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

    // Draw a  green circle
    sf::CircleShape circle(50); // Radius 50

    circle.setFillColor(sf::Color::Green);
    circle.setPosition(window.getSize().x/2 - circle.getRadius(), window.getSize().y / 2 - circle.getRadius()); // Set position

    //Draw a red square
    sf::RectangleShape square(sf::Vector2f(100.f, 100.f)); // equal width and height
    square.setFillColor(sf::Color::Red);
    square.setPosition(window.getSize().x/6, window.getSize().y/6); //setting the position
  //   square.setPosition(100,250);

    //Draw a triangle
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(600.f, 200.f));
    triangle.setPoint(1, sf::Vector2f(500.f, 400.f));
    triangle.setPoint(2, sf::Vector2f(700.f, 400.f));
    triangle.setFillColor(sf::Color::Magenta);

  //  gameloop();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Check for window closure
            if (event.type == sf::Event::Closed)
                window.close();
        }

     sf::Texture outscal_texture;                                           // sf::Texture.texture
    outscal_texture.loadFromFile("assets/textures/outscal_logo.png");      // texture.loadfromfile(pathtoimage.png)

    sf::Sprite outscal_sprite;                                             // sf::Sprite sprite;
    outscal_sprite.setTexture(outscal_texture);                            //  sprite.setTexture(texture);

    // set its position, rotation, scale:
    outscal_sprite.setPosition(100, 200);
    outscal_sprite.setRotation(45);
    outscal_sprite.setScale(0.5, 0.5);

    sf::Font font;
    font.loadFromFile("assets/fonts/bubbleBobble.ttf");
    sf::Text text("SFML is Awesome!", font, 50);
    text.setFillColor(sf::Color::White);



        // window.setFramerateLimit(60);
        window.display();
        window.clear(sf::Color::Blue);
        window.draw(circle);
        window.draw(square);
        window.draw(triangle);
        window.draw(outscal_sprite);
        window.draw(text);
     
    }

       
      


    return 0;
}