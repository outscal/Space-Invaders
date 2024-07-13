#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\Interface\IUIController.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\ImageView.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\Button\ButtonView.h"
#include <SFML/Graphics.hpp>
namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController: public IUIController
		{
		private:
			// Constants:
			const float button_width = 400.f;
			const float button_height = 140.f;
			//Button Positions
			const float play_button_y_position = 500.f;
			const float instructions_button_y_position = 700.f;
			const float quit_button_y_position = 900.f;
			
			const float background_alpha = 85.f;
			sf::RenderWindow* game_window;
			
			// UI Emements:
			UIElement::ImageView* background_image;
			UIElement::ButtonView* play_button;
			UIElement::ButtonView* instructions_button;
			UIElement::ButtonView* quit_button;
			
			void CreateImage();
			void CreateButtons();
			void InitializeBackgroundImage();
			void InitializeButtons();
			void RegisterButtonCallback();

			void PlayButtonCallback();
			void InstructionsButtonCallback();
			void QuitButtonCallback();

			void Destroy();
		public:
			MainMenuUIController();
			~MainMenuUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;

		//	//BG Image visual and init.
		//	void InitializeBackgroundImage();
		//	void ScaleBackgroundImage();
		//	
		//	//Button visual and init.
		//	void InitializeButtons();
		//	bool LoadButtonTexturesFromFile();
		//	void SetButtonSprites();
		//	void ScaleAllButtons();
		//	void ScaleSpecificButton(sf::Sprite* button_to_scale);
		//	void PositionButtons();
		//	
		//	//Button Interactions
		//	void ProcessButtonInteractions();
		//	bool ClickedButton(sf::Sprite*, sf::Vector2f);
		//public:
		//	MainMenuUIController();
		//	void Initialize();
		//	void Update();
		//	void Render();
		};
	}
}
