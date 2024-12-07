#include "../../HeaderFiles/Element/Bunker/BunkerView.h"
#include "../../HeaderFiles/Element/Bunker/BunkerController.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"


namespace Element
{
	namespace Bunker
	{
		using namespace Global;
	

		BunkerView::BunkerView()
		{

		}

		BunkerView::~BunkerView()
		{

		}

		void BunkerView::initialize(BunkerController* controller)
		{
			bunkerController = controller;
			gameWindow = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow();
			initializeBunkerSprite();
		}

		void BunkerView::update()
		{
			bunkerSprite.setPosition(bunkerController->getBunkerPosition());
		}

		void BunkerView::render()
		{
			gameWindow->draw(bunkerSprite);
		}

		void BunkerView::initializeBunkerSprite()
		{
			if (bunkerTexture.loadFromFile(bunker_texture_path))
			{
				bunkerSprite.setTexture(bunkerTexture);
				scaleBunkerSprite();
			}
		}

		void BunkerView::scaleBunkerSprite()
		{
			bunkerSprite.setScale(
				static_cast<float>(bunkerSpriteWidth) / bunkerSprite.getTexture()->getSize().x,
				static_cast<float>(bunkerSpriteHeight) / bunkerSprite.getTexture()->getSize().y);
		}



	}
}