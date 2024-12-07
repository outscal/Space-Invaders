#pragma once

//#include "../../Header/Graphic/GraphicService.h"
//#include "../Player/PlayerView.h"
//#include "../Player/PlayerModel.h"


namespace Player
{
	class GraphicService;
	enum class PlayerState;
	class PlayerModel;
	class PlayerView;

	class PlayerController
	{
	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		sf::Vector2f getPosition();

	private:

		PlayerModel* player_model;
		PlayerView* player_view;

		void processInput();
		void moveLeft();
		void moveRight();



	};

}

