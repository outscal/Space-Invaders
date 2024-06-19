#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Element/Bunker/BunkerModel.h"


namespace Element
{
	namespace Bunker
	{
		class BunkerView;
		class BunkerController
		{
		public:
			BunkerController();
			~BunkerController();

			void initialize(Bunker::BunkerData data);
			void update();
			void render();

			sf::Vector2f getBunkerPosition();

		private:
			BunkerView* bunker_view;
			BunkerData bunker_data;
		};
	}
}


