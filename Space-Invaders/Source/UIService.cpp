#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Main\GameService.h"
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
		destroy();
	}
	void UIService::Initialize()
	{
		initializeControllers();
	}
	void UIService::Update()
	{

	}
	void UIService::Render()
	{

	}
	void UIService::initializeControllers()
	{
		main_menu_controller->Initialize();
	}
	void UIService::destroy()
	{
		delete(main_menu_controller);
	}
}