#include "../../Header/UIService/UIElement/ImageView.h"

namespace UI
{
	namespace UIElement
	{
		UI::UIElement::ImageView::ImageView()
		{
		}

		ImageView::~ImageView()
		{
		}

		void ImageView::initialize(sf::String texture_path, float image_height, float image_width, sf::Vector2f position)
		{
			UIView::initialize();
			setTexture(texture_path);
			setScale(image_height, image_width);
			setPosition(position);
		}

		void ImageView::update()
		{
			UIView::update();
		}

		void ImageView::render()
		{
			UIView::render();
			if (ui_state == UIState::VISIBLE)
			{
				game_window->draw(image_sprite);
			}
		}

		void ImageView::setTexture(sf::String texture_path)
		{
			if (image_texture.loadFromFile(texture_path))
			{
				image_sprite.setTexture(image_texture);
			}
		}

		void ImageView::setScale(float width, float height)
		{
			float scale_x = width / image_sprite.getTexture()->getSize().x;
			float scale_y = height / image_sprite.getTexture()->getSize().y;

			image_sprite.setScale(scale_x, scale_y);
		}

		void ImageView::setPosition(sf::Vector2f image_position)
		{
			image_sprite.setPosition(image_position);
		}

		void ImageView::setRotation(float rotation_angle)
		{
			image_sprite.setRotation(rotation_angle);
		}

		void ImageView::setOriginAtCentre()
		{
			image_sprite.setOrigin(image_sprite.getLocalBounds().width / 2, image_sprite.getLocalBounds().height / 2);
		}

		void ImageView::setImageAlpha(float alpha)
		{
			sf::Color color = image_sprite.getColor();
			color.a = alpha;
			image_sprite.setColor(color);
		}

		void ImageView::setCentreAlinged()
		{
			float x_position = (game_window->getSize().x / 2) - (image_sprite.getGlobalBounds().width / 2);
			float y_position = image_sprite.getGlobalBounds().getPosition().y;

			image_sprite.setPosition(x_position, y_position);
		}

	}
}
