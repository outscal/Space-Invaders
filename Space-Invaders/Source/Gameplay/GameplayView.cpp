#include "../../HeaderFiles/Gameplay/GameplayView.h"
#include <SFML/Graphics.hpp>
#include "../../HeaderFiles/Graphic/GraphicService.h"
#include "../../HeaderFiles/Global/ServiceLocator.h"
#include <iostream>
using namespace std;

namespace Gameplay
{
	using namespace Global;
    using namespace Graphic;

	GameplayView::GameplayView()
	{

	}

	GameplayView::~GameplayView()
	{

	}

	void GameplayView::initialize()
	{
		gameWindow = ServiceLocator::getInstance()->GetGraphicService()->GetGameWindow();
		initializeBackgroundSprite();

	}

	void GameplayView::update()
	{

	}

	void GameplayView::render()
	{
		gameWindow->draw(backgroundSprite);
	}

	void GameplayView::initializeBackgroundSprite()
	{
		if (backgroundTexture.loadFromFile(backgroundTexturePath))
		{
			backgroundSprite.setTexture(backgroundTexture);
			scaleBackgroundSprite();
		}
	}
	void GameplayView::scaleBackgroundSprite()
	{
		backgroundSprite.setScale
		(
			static_cast <float> (gameWindow->getSize().x) / backgroundSprite.getTexture()->getSize().x,
			static_cast <float> (gameWindow->getSize().y) / backgroundSprite.getTexture()->getSize().y
		);
	}

}