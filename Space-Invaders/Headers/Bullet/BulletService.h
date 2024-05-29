#pragma once
namespace Bullet
{
	class BulletService
	{
	private:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
	};
}