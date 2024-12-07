#pragma once
#include <SFML/Graphics.hpp>
#include "../../HeaderFiles/Element/Bunker/BunkerModel.h"

namespace Element
{
	
	namespace Bunker
	{
		class BunkerView;

class BunkerController

{
    private:

		BunkerData bunkerData;
		BunkerView* bunkerView;

    public:
		
		BunkerController();
		~BunkerController();

		void update();
		void initialize(BunkerData data);
		void render();

		sf::Vector2f getBunkerPosition();


};
	}
}
