#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
    class PlayerView;
    class PlayerModel;

    enum class PlayerState;

    class PlayerController
    {
    private:
        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        sf::Vector2f getPlayerPosition();
        int getPlayerScore();
        PlayerState getPlayerState();


    };
    void PlayerController::processPlayerInput()
    {
        EventService* event_service = ServiceLocator::getInstance()->getEventService();

        if (event_service->pressedLeftArrowKey() || event_service->pressedAKey()) moveLeft();
        if (event_service->pressedRightArrowKey() || event_service->pressedDKey()) moveRight();
        if (event_service->pressedLeftMouseButton()) fireBullet(); //this
    
        void PlayerController::fireBullet()
        {
            ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
                player_model->getPlayerPosition() + player_model->barrel_position_offset,
                Bullet::MovementDirection::UP);

}