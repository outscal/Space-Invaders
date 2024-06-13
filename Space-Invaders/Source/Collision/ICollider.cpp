#include"C:\Users\avnis\OneDrive\Desktop\Avnish Space Invaders\Space-Invaders-SFML\Space-Invaders\Headers\Collision\ICollider.h"

namespace Collision
{
	ICollider::ICollider() { collision_state = CollisionState::ENABLED; }

	ICollider::~ICollider() { }

	void ICollider::EnableCollision() { collision_state = CollisionState::ENABLED; }

	void ICollider::DisableCollision() { collision_state = CollisionState::DISABLED; }

	CollisionState ICollider::GetCollisionState() { return collision_state; }
}