#include "../../Header/Gameplay/GameplayView .h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header//Graphic/GraphicService.h"
#include "../../Header/Global/Config.h"


namespace Gameplay
{
	using namespace Global;
	using namespace Graphic;
	Gameplay::GameplayView::GameplayView()
	{
		game_window = nullptr;
	}

	Gameplay::GameplayView::~GameplayView()
	{
	}

	void Gameplay::GameplayView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeBackgroundImage();
	}

	void Gameplay::GameplayView::update()
	{
	}

	void Gameplay::GameplayView::render()
	{
		game_window->draw(background_sprite);
	}

	void GameplayView::initializeBackgroundImage()
	{
		if (background_texture.loadFromFile(Config::background_texture_path))
		{
			background_sprite.setTexture(background_texture);
			setBackgroundScale();
		}
	}

	void GameplayView::setBackgroundScale()
	{
		background_sprite.setScale(
			static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
		);
	}

}
