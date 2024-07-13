#pragma once
#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\UI\UIService.h"
namespace UI
{
	namespace UIElement
	{
		class UIView;
		class ImageView : public UIView
		{
		protected:
			sf::Texture image_texture;
			sf::Sprite image_sprite;

		public:
			ImageView();
			virtual ~ImageView();

			//lifecycle methods
			virtual void Initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position);
			virtual void Update() override;
			virtual void Render() override;

			virtual void SetTexture(sf::String texture_path);
			virtual void SetScale(float width, float height);
			virtual void SetPosition(sf::Vector2f position);
			virtual void SetRotation(float rotation_angle);
			virtual void SetOriginAtCentre();
			virtual void SetImageAlpha(float alpha);
			virtual void SetCentreAlinged();
		};
	}
}
