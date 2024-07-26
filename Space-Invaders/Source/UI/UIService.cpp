#include "../../Header/UI/UIService.h"
#include"../../Header/UI/MainMenuUI/MainMenuUIController.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	UIService::UIService()
	{
		main_menu_controller = nullptr;
		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
	}

	UIService::~UIService()
	{
		destory();
	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::update()
	{

	}

	void UIService::render()
	{

	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
	}

	void UIService::destory()
	{
		delete(main_menu_controller);
	}
}