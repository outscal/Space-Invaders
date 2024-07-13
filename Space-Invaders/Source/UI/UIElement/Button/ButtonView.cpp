#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIElement\Button\ButtonView.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Global\ServiceLocator.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Event\EventService.h"
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Sound\SoundService.h"
namespace UI
{
    namespace UIElement
    {
        using namespace Event;
        using namespace Global;

        ButtonView::ButtonView() = default;

        ButtonView::~ButtonView() = default;

        void ButtonView::Initialize(sf::String title, sf::String texture_path, float button_width, float button_height, sf::Vector2f position)
        {
            ImageView::Initialize(texture_path, button_width, button_height, position);
            button_title = title;
        }

        void ButtonView::RegisterCallbackFuntion(CallbackFunction button_callback)
        {
            callback_function = button_callback;
        }

        void ButtonView::Update()
        {
            ImageView::Update();

            if (ui_state == UIState::VISIBLE)
            {
                HandleButtonInteraction();
            }
        }

        void ButtonView::Render()
        {
            ImageView::Render();
        }

        void ButtonView::HandleButtonInteraction()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (ClickedButton(&image_sprite, mouse_position))
            {
                if (callback_function) callback_function();
            }
        }

        bool ButtonView::ClickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            return ServiceLocator::GetInstance()->GetEventService()->PressedLMB() &&
                button_sprite->getGlobalBounds().contains(mouse_position);
        }

        void ButtonView::PrintButtonClicked()
        {
            printf("Clicked %s\n", button_title.toAnsiString().c_str());
        }
    }
}