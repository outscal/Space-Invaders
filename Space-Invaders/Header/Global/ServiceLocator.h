#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Player/PlayerService.h"
#include "../../header/Time/TimeService.h"
#include "../../header/Enemy/EnemyService.h"
#include "../../header/Gameplay/GameplayService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Event::EventService* event_service;
        Graphic::GraphicService* graphic_service;
        UI::UIService* ui_service;
        Time::TimeService* time_service;
        Gameplay::GameplayService* gameplay_service;
        Player::PlayerService* player_service;
        Enemy::EnemyService* enemy_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Event::EventService* getEventService();
        Graphic::GraphicService* getGraphicService();
        UI::UIService* getUIService();
        Time::TimeService* getTimeService();
        Gameplay::GameplayService* getGameplayService();
        Player::PlayerService* getPlayerService();
        Enemy::EnemyService* getEnemyService();
        void deleteServiceLocator();
    };
}