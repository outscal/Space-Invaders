#pragma once
#include <SFML/Graphics.hpp>

class ICollectible
{
public:
	virtual void onCollected() = 0;
	virtual void initialCollectible(sf::Vector2f collectiblePosition) = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual ~ICollectible() {};
	virtual sf::Vector2f getCollectiblePosition() = 0;

private:

};

