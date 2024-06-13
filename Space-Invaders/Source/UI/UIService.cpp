#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\Interface\IUIController.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Graphic\GraphicService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Main\GameService.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\MainMenu\MainMenuUIController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include "C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\Text\TextView.h"


namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace Interface;
	using namespace UIElement;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		CreateControllers();
	}
	void UIService::CreateControllers()
	{
		main_menu_controller = new MainMenuUIController();
	}
	UIService::~UIService()
	{
		Destroy();
	}
	void UIService::Initialize()
	{
		InitializeControllers();
		TextView::InitializeTextView();
		//main_menu_controller->Initialize();
	}
	void UIService::Update()
	{	
		IUIController* ui_controller = GetCurrentUIController();
		if (ui_controller) ui_controller->Update();
	}
	void UIService::Render()
	{	
		IUIController* ui_controller = GetCurrentUIController();
		if (ui_controller) ui_controller->Render();
	}
	void UIService::ShowScreen()
	{
		IUIController* ui_controller = GetCurrentUIController();
		if (ui_controller) ui_controller->Show();
	}
	void UIService::InitializeControllers()
	{
		main_menu_controller->Initialize();
	}
	IUIController* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller;

		default:
			return nullptr;
		}
	}
	void UIService::Destroy()
	{
		delete(main_menu_controller);
	}

	namespace UIElement
	{
		using namespace Global;
		using namespace Graphic;

		UIView::UIView() = default;

		UIView::~UIView() = default;

		void UIView::Initialize()
		{
			game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			ui_state = UIState::VISIBLE;
		}

		void UIView::Update() { }

		void UIView::Render() { }

		void UIView::Show()
		{
			ui_state = UIState::VISIBLE;
		}

		void UIView::Hide()
		{
			ui_state = UIState::HIDDEN;
		}
	}
}
