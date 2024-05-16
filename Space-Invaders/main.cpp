

#include <SFML/Graphics.hpp>

int main()
{
 // Defined the videon mode (dimensiond)
	sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));
	
  //Change window size
 //sf::RenderWindow window(sf::VideoMode(1280, 720), " Resizeable Window ", sf::Style::Resize);


// Create a Window object with specific dimensions and title
		sf::RenderWindow* window = new sf::RenderWindow(videoMode, " My SFML Window ");


  //Enable fullscreen mode:
  //sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0]   " Fullscreen Window",sf::Style::Fullscreen);



		//Configarin window Position
	//	window->setPosition(sf::Vector2(100, 100));
	
			
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
		window->clear(sf::Color::Green);
		
		//Draw your content here...
		

		//Display what was drawn
		window->display();


	}



	return 0;
}