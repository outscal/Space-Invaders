#pragma once
#include "../../Header/UIService/interface/IUIController.h"

namespace UI
{
	class UIController:public Interface::IUIController
	{
	public:
		UIController();
		~UIController();

		void initialize() override;
		void update() override;
		void render() override;

		void show() override;

	private:

	};


}
