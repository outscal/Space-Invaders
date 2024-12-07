#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../HeaderFiles/Element/Bunker/BunkerController.h"
#include"../../HeaderFiles/Element/Bunker/BunkerModel.h"
namespace Element
{
	class ElementService
	{
	private:

		const std::vector<Bunker::BunkerData> bunkerDataList = {
			Bunker::BunkerData(sf::Vector2f(130.0f,800.0f)),
			Bunker::BunkerData(sf::Vector2f(430.0f,800.0f)),
			Bunker::BunkerData(sf::Vector2f(730.0f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(1130.0f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(1430.0f, 800.f)),
			Bunker::BunkerData(sf::Vector2f(1730.0f, 800.f)) };

		std::vector<Bunker::BunkerController*> bunkerList;

		void destroy();

	public:
		ElementService();
		~ElementService();
		void initialize();
		void update();
		void render();

	};
}
