#pragma once
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Collectible\ICollectible.h"

namespace Powerup
{
    class PowerupView;
    class PowerupModel;

    enum class PowerupType;

    class PowerupController : public Collectible::ICollectible
    {
    protected:
        PowerupView* powerup_view;
        PowerupModel* powerup_model;

        void UpdatePowerupPosition();
        void HandleOutOfBounds();

    public:
        PowerupController(PowerupType type);
        virtual ~PowerupController();

        void Initialize(sf::Vector2f position) override;
        void Update() override;
        void Render() override;

        void OnCollected() override;

        sf::Vector2f GetCollectiblePosition() override;
        PowerupType GetPowerupType();
    };
}
