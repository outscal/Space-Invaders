

#include <SFML/Graphics.hpp>

int main()
{
 // Defined the videon mode (dimensiond)
	sf::VideoMode videoMode = *(new sf::VideoMode(1920, 1080));
	
	
// Create a Window object with specific dimensions and title
		sf::RenderWindow* window = new sf::RenderWindow(videoMode, " My SFML Window ");

	
 
			//Game loop to keep the window open
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event)) 

		{
			//Check for window closure
			if (event.type == sf::Event::Closed)
			window->close();

		}

		//Clear the window
		window->clear(sf::Color::Black);
		
		//Draw your content here...
		
	
		//Draw a circle
		sf::CircleShape circle(50);//Radius 50
		circle.setFillColor(sf::Color::Green);
		circle.setPosition(400, 300);// position
		window->draw(circle);
		sf::RectangleShape square(sf::Vector2f(100, 100));
		square.setFillColor(sf::Color::Red);
		square.setPosition(400, 200);
		window->draw(square);
		sf::CircleShape triangle(80, 3); 
		triangle.setFillColor(sf::Color::Blue);
		triangle.setPosition(370, 78);
		window->draw(triangle);
		
		sf::Texture outscal_texture;
		outscal_texture.loadFromFile("assets/textures/outscal_logo.png");

		sf::Sprite outscal_sprite;
		outscal_sprite.setTexture(outscal_texture);

		outscal_sprite.setPosition(300,400 ); // Position
		outscal_sprite.setRotation(0); // Rotation in degrees
		outscal_sprite.setScale(0.5, 0.5); // Scale factor

		window->draw(outscal_sprite);

		sf::Font font;
		font.loadFromFile("assets/fonts/OpenSans.ttf");
		sf::Text text("Hello SFML!", font, 50);
		text.setFillColor(sf::Color::Red);
		window->draw(text);

		//Display what was drawn
		window->display();


	}



	return 0;
}