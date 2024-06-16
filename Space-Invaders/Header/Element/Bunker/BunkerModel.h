#pragma once
#include <SFML/Graphics.hpp>

namespace Element
{
	namespace Bunker
	{
		struct BunkerData
		{
			BunkerData();
			BunkerData(sf::Vector2f position);
			sf::Vector2f position;
		};
	}

}
