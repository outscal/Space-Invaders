#pragma once

namespace UI
{
	namespace Interface
	{
		class IUIController
		{
		public:
			
			virtual ~IUIController() {};

			virtual void initialize() =0;
			virtual void update() =0;
			virtual void render() =0;

			virtual void show() = 0;

		private:

		};

	}
}
