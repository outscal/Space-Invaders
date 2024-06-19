#pragma once

namespace Bullet
{
	class BulletService
	{
	public:
		BulletService();
		~BulletService();



	private:
		void initialize();
		void update();
		void render();
	};
}


