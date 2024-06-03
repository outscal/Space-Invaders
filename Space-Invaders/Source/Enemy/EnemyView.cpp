#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\Config.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphic;
	using namespace UI::UIElement;
	
	EnemyView::EnemyView() { CreateUIElements(); }
	EnemyView::~EnemyView() { Destroy(); }
	void EnemyView::Initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		//game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeImage();//Get the specific enemy type
	}
	void EnemyView::CreateUIElements()
	{
		enemy_image = new ImageView();
	}
	void EnemyView::InitializeImage()
	{
		enemy_image->Initialize(GetEnemyTexturePath(), enemy_sprite_width, enemy_sprite_height, enemy_controller->GetEnemyPosition());
	}
	sf::String EnemyView::GetEnemyTexturePath()
	{
		switch (enemy_controller->GetEnemyType())
		{
		case Enemy::EnemyType::ZAPPER:
			return Config::zapper_texture_path;
		case Enemy::EnemyType::SUBZERO:
			return Config::subzero_texture_path;
		case Enemy::EnemyType::UFO:
			return Config::ufo_texture_path;
		}
	}
	void EnemyView::Update()
	{
		enemy_image->SetPosition(enemy_controller->GetEnemyPosition());
		enemy_image->Update();
	}
	void EnemyView::Render()
	{
		//game_window->draw(enemy_sprite);
		enemy_image->Render();
	}
	void EnemyView::Destroy()
	{
		delete(enemy_image);
	}
}