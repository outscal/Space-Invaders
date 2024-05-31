#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupView.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Powerups\PowerupModel.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	PowerupController::PowerupController(PowerupType type)
	{
		powerup_view = new PowerupView();
		powerup_model = new PowerupModel(type);
	}

	PowerupController::~PowerupController()
	{
		delete (powerup_view);
		delete (powerup_model);
	}

	void PowerupController::Initialize(sf::Vector2f position)
	{
		powerup_model->Initialize(position);
		powerup_view->Initialize(this);
	}

	void PowerupController::Update()
	{
		UpdatePowerupPosition();
		powerup_view->Update();
	}

	void PowerupController::Render()
	{
		powerup_view->Render();
	}

	void PowerupController::OnCollected()
	{
	}

	void PowerupController::UpdatePowerupPosition()
	{
		sf::Vector2f currentPosition = powerup_model->GetPowerupPosition();
		currentPosition.y += powerup_model->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		powerup_model->SetPowerupPosition(currentPosition);
	}

	void PowerupController::HandleOutOfBounds()
	{
		sf::Vector2f powerupPosition = GetCollectiblePosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		if (powerupPosition.x < 0 || powerupPosition.x > windowSize.x ||
			powerupPosition.y < 0 || powerupPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetPowerupService()->DestroyPowerup(this);
		}
	}

	sf::Vector2f PowerupController::GetCollectiblePosition()
	{
		return powerup_model->GetPowerupPosition();
	}

	PowerupType PowerupController::GetPowerupType()
	{
		return powerup_model->GetPowerupType();
	}
}