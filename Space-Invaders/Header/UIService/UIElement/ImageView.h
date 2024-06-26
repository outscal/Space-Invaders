#pragma once
#include "../../Header/UIService/UIService.h"
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace UIElement
	{
		class ImageView:public UIView
		{
		public:
			ImageView();
			virtual ~ImageView();

			virtual void initialize(sf::String texture_path, float image_height, float image_width,sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;

			virtual void setTexture(sf::String texture_path);
			virtual void setScale(float width, float height);
			virtual void setPosition(sf::Vector2f image_position);
			virtual void setRotation(float rotation_angle);
			virtual void setOriginAtCentre();
			virtual void setImageAlpha(float alpha);
			virtual void setCentreAlinged();


		protected:
			sf::Texture image_texture;
			sf::Sprite image_sprite;
		};


	}
}
