#include <SFML/Graphics.hpp>

class Player {
private:
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	int player_score = 0;
	int health = 3;
	int movement_speed=10;
	sf::Vector2f position = sf::Vector2f(200,200);

public:
	void takeDamage(int amt) {

	}

	void shootBullets() {

	}

	void move() {

	}
};

int main() {


	sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

	sf::RenderWindow* window = new sf::RenderWindow(videoMode, "My SFML Window");


	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear(sf::Color::Yellow);


		//circle
		sf::CircleShape circle(50); 
		circle.setFillColor(sf::Color::Green);
		circle.setPosition(300	, 100);
		window->draw(circle);

		//square
		sf::RectangleShape square(sf::Vector2f(100, 100));
		square.setFillColor(sf::Color::Red);
		square.setPosition(100, 100);
		window->draw(square);


		//triangle
		sf::ConvexShape triangle;
		triangle.setPointCount(3);
		triangle.setPoint(0,sf::Vector2f(0, 100));
		triangle.setPoint(1, sf::Vector2f(50, 0));
		triangle.setPoint(2, sf::Vector2f(100, 100));
		triangle.setFillColor(sf::Color::Blue);
		triangle.setPosition(500, 100);
		window->draw(triangle);


		//image
		sf::Texture outscal_texture;
		outscal_texture.loadFromFile("assets/textures/outscal_logo.png");
		sf::Sprite outscal_sprite;
		outscal_sprite.setTexture(outscal_texture);
		outscal_sprite.setPosition(300, 300);
		outscal_sprite.setRotation(45);
		outscal_sprite.setScale(0.5, 0.5);
		window->draw(outscal_sprite);

		//text
		sf::Font font;
		font.loadFromFile("assets/fonts/OpenSans.ttf");
		sf::Text text("SFML is Awesome", font, 50);
		text.setFillColor(sf::Color::Red);
		window->draw(text);


		window->display();
	}

	return 0;
}
