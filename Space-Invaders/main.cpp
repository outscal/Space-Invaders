#include <SFML/Graphics.hpp>

int main() {


	sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

	sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");


	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear(sf::Color::White);


		sf::CircleShape circle(50); 
		circle.setFillColor(sf::Color::Green);
		circle.setPosition(300	, 100);

		window->draw(circle);

		sf::RectangleShape square(sf::Vector2f(100, 100));
		square.setFillColor(sf::Color::Red);
		square.setPosition(100, 100);
		window->draw(square);



		sf::ConvexShape triangle;
		triangle.setPointCount(3);
		triangle.setPoint(0,sf::Vector2f(0, 100));
		triangle.setPoint(1, sf::Vector2f(50, 0));
		triangle.setPoint(2, sf::Vector2f(100, 100));
		triangle.setFillColor(sf::Color::Blue);
		triangle.setPosition(500, 100);

		window->draw(triangle);

		window->display();
	}

	return 0;
}
