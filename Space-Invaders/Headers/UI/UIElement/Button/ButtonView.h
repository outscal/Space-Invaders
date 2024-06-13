#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\ImageView.h"
#include <functional>

namespace UI
{
	namespace UIElement
	{
		class ButtonView : public ImageView
		{
		private:
			// Define a function pointer type for the callback function
			using CallbackFunction = std::function<void()>;

			// Store the callback function
			CallbackFunction callback_function = nullptr;

			void PrintButtonClicked();

		protected:
			sf::String button_title;

			virtual void HandleButtonInteraction();
			virtual bool ClickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position);

		public:
			ButtonView();
			virtual ~ButtonView();

			virtual void Initialize(sf::String title, sf::String texture_path, float button_width, float button_height, sf::Vector2f position);
			virtual void Update() override;
			virtual void Render() override;

			void RegisterCallbackFuntion(CallbackFunction button_callback);
		};
	}
}