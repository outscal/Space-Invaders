#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Event\EventService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Player\PlayerService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Time\TimeService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Enemy\EnemyService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Gameplay\GameplayService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Element\ElementService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Sound\SoundService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Bullet\BulletService.h"



namespace Global
{
    
    class ServiceLocator
    {
    private:
        // Private Attributes:
        Graphic::GraphicService* graphic_service;
        Event::EventService* event_service;
        Player::PlayerService* player_service;
        Time::TimeService* time_service;
        UI::UIService* ui_service;
        Enemy::EnemyService* enemy_service;
        Gameplay::GameplayService* gameplay_service;
        Element::ElementService* element_service;
        Sound::SoundService* sound_service;
        Bullet::BulletService* bullet_service;
        // Private Constructor and Destructor:
        ServiceLocator();
        ~ServiceLocator();

        // Private Methods:
        void CreateServices();
        void ClearAllServices();

    public:
        // Public Methods:
        static ServiceLocator* GetInstance();

        void Initialize();
        void Update();
        void Render();

        // Methods to Get Specific Services: 
        Graphic::GraphicService* GetGraphicService();
        Event::EventService* GetEventService();
        Player::PlayerService* GetPlayerService();
        Time::TimeService* GetTimeService();
        UI::UIService* GetUIService();
        Enemy::EnemyService* GetEnemyService();
        Gameplay::GameplayService* GetGameplayService();
        Element::ElementService* GetElementService();
        Sound::SoundService* GetSoundService();
        Bullet::BulletService* GetBulletService();
    };

}
