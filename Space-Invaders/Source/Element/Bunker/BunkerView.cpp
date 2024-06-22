#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h";


namespace Element 
{
	namespace Bunker 
	{
		using namespace Global;

		Element::Bunker::BunkerView::BunkerView()
		{
			//bunker_controller = nullptr;
		}
		BunkerView::~BunkerView()
		{
			//delete(bunker_controller);
		}

		void BunkerView::initialize(BunkerController* controller)
		{
			bunker_controller = controller;
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeSprite();
		}
		void BunkerView::update()
		{
			bunker_sprite.setPosition(bunker_controller->getBunkerPosition());
		}
		void BunkerView::render()
		{
			game_window->draw(bunker_sprite);
		}
		void BunkerView::initializeSprite()
		{
			if (bunker_texture.loadFromFile(Config::bunker_texture_path))
			{
				bunker_sprite.setTexture(bunker_texture);
				scaleSprite();
			}
		}
		void BunkerView::scaleSprite()
		{
			bunker_sprite.setScale(
				static_cast<float>(bunker_width) / bunker_sprite.getTexture()->getSize().x,
				static_cast<float>(bunker_height) / bunker_sprite.getTexture()->getSize().y
			);
		}
	}
}


